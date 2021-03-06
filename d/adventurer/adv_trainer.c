//#pragma save_binary

// teacher.c
#include <daemons.h>

mapping lessons;

// This function initializes the lessons the trainer can teach.
void set_lessons( mapping available_lessons )
{
	lessons = available_lessons;
}

void init()
{
	add_action( "do_train", "train" );
}

int check_trainee( object trainee ) { return 1; }

int do_train(string arg)
{
	int skill, exp, explore,EXPLORE1,total_points;

	if( !arg || arg=="" || undefinedp(lessons[arg]) )
		return notify_fail( 
			"你要训练什麽技能？\n" );
        explore  = (int)this_player()->query_explore_points();
	total_points=EXPLORE_D->query_total_explore();
	EXPLORE1=explore*100/total_points;
	if (EXPLORE1 > 100) EXPLORE1 =100;
	
	if( EXPLORE1 < lessons[arg][2] )
	        return notify_fail("艾佛瑞说道: 没有冒险精神的冒险者，不值得我传授技巧!\n");
	if( !this_object()->check_trainee( this_player() ) )
		return 0;

	skill = (int)this_player()->query_perm_skill(arg);
	if( skill > lessons[arg][1] )
		return notify_fail( 
			"这项技能在这里你只能学到 " + lessons[arg][1] + "。\n");

	exp = (int)STATS_D->query_skill_exp(skill) * lessons[arg][0] / 100;
	if( exp > (int)this_player()->query_exp_stock() )
		return notify_fail( 
			"提升这项技能需要 " + exp + " 点经验，但是你的经验不够。\n");

	this_player()->gain_experience( -exp );
	STATS_D->train_skill( this_player(), arg );
	write( "你的" + to_chinese(arg) + "技能现在提升到 " + 
		this_player()->query_perm_skill(arg) + " 了。\n");
	return 1;
}
