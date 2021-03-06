//#pragma save_binary

// This is a study object which provides a simple command to let player
// list and learn tricks.
// Created by Annihilator@Eastern.Stories (12-17-93)
// Updated by Kyoko@Eastern.Stories (3-10-94)

#include <mudlib.h>

mapping tricks;

// This function setups the tricks can be learned. The format is:
// ([ <trick-name> : ({ <trick_system>, <skill_required>, <max_level>, 
//                      <skill_per_level>, <exp_proportion(%)>  }), 
//    <trick-name> : ({ <trick_system>, <skill_required>, <max_level>, 
//                      <skill_per-_evel>, <exp_proportion(%)>  }), 
//                         :
//                         :
void set_tricks(mapping s)
{
	tricks = s;
}

mapping query_tricks()
{
	return tricks;
}

// This function checks if a player can learn a certain trick. If the third
// argument is given, trick level is also checked. Return 1 if the player
// can learn the trick ( at specified level, or 0 for default )
varargs int can_learn_trick(object player, string trick, int level)
{
	int extra;

	if( !tricks || !mapp(tricks) || !trick || undefinedp(tricks[trick]) )
		return 0;
	if( !level ) {
		if( (int)player->query_skill( tricks[trick][0] ) >= tricks[trick][1] )
			return 1;
		else return 0;
	} else {
		if( level > tricks[trick][2] ) return 0;
		if( (int)player->query_skill( tricks[trick][0] ) >=
		       tricks[trick][1] + tricks[trick][3] )
			return 1;
		else return 0;
	}
}

// This function returns experience required to raise a trick level. If
// something goes wrong, -1 is returned.
int raise_cost(object player, string trick)
{
	int skill, level, exp;

	if( !tricks || !mapp(tricks) || !trick || undefinedp(tricks[trick]) )
		return -1;
	if( undefinedp(level= (int)player->query("tricks/"+trick)) )
		return 0;
	if( level >= tricks[trick][2] ) return -2;
	skill = tricks[trick][1] + tricks[trick][3] * (level+1);
	if( skill > 100 ) skill = 100;
	if( (int)player->query_skill( tricks[trick][0] ) < skill )
		return 0;
	exp = tricks[trick][4] * tricks[trick][1] * tricks[trick][1] 
	      * (level+1) * (level+1) / 100 ;
	exp -= ((int)player->query_perm_stat("pie")-15) * exp / 30;
	return exp;
}

// *************************************************************************
// The following are default commands for study rooms. You can alter it in
// your code if you think it is needed.
// *************************************************************************

void init()
{
	add_action( "do_study", "study" );
	add_action( "do_raise", "thinking" );
	add_action( "do_read","read");
}

int do_read(string arg)
{
	string *trick;
	int i;

	if ( ! arg) 
		return notify_fail("你要读什麽？\n");
	trick = keys(tricks);
	if ( (i = member_array( arg,trick)) < 0 )
		return notify_fail("你翻遍了书也找不到你要的资料。\n");
	write("你把巨书翻开，翻到有关"+to_chinese(trick[i])+"的那一页，上面写著 :\n\n");
	cat("/d/thief/doc/tricks/"+trick[i]);
	return 1;
}

void view_catalog()
{
	mapping tricks;
	string *s;
	int i;
	
	write("书的目录上写著 : \n\n");
	printf( "%-30s  %-15s  %-8s  %-8s\n",
		"计策名称","计策种类","所需技能","最大级数");
	write( "=====================================================================\n");
	tricks = query_tricks();
	s = keys(tricks);
	for( i=0; i<sizeof(s); i++ ) {
		printf( "%-30s  %-15s  %5d     %6d\n",
			to_chinese(s[i]) + " (" + s[i] + ")",
			to_chinese(tricks[s[i]][0]),
			tricks[s[i]][1], tricks[s[i]][2] );
	}
	write( "=====================================================================\n");
	write("\n你可以翻翻书，读读(read)你所想知道的资料。\n");
}

int do_study(string arg)
{

//	if ( !wizardp(this_player()) )
//		return notify_fail(
//			"目前暂不开放学习。\n");
	if( !arg || arg=="" )
		return notify_fail(
			"指令格式: study <计策名称>\n");
	if( !undefinedp( this_player()->query("tricks/"+arg) ) )
		return notify_fail(
			"这个计策你已经学会了，你可以□试思考(thinking)更高级的运用方式。\n");
	if( !can_learn_trick( this_player(), arg ) )
		return notify_fail(
			"对不起，你现在对诡计学的认识还没有办法了解这种计策....。\n");
	write("经过一番钻研，你终於了解了" + to_chinese(arg) + "的基本关键！\n");
	this_player()->set("tricks/"+arg, 0);
	return 1;
}

int do_raise(string arg)
{
	mapping my_tricks;
	string *s;
	int i, exp;

	if( !arg || arg=="" ) {
		my_tricks = this_player()->query("tricks");
		if( !my_tricks || !mapp(my_tricks) || sizeof(my_tricks) < 1 ) {
			write( "你目前并没有学到任何计策。\n");
			return 1;
		}
		s = keys(my_tricks);
		printf( "%-30s  %-8s  %s\n","计策名称","目前等级","提升等级所需经验");
		write( "============================================================\n");
		for( i=0; i<sizeof(s); i++ ) {
			if( undefinedp( tricks[s[i]] ) ) continue;
			exp = raise_cost( this_player(), s[i] );
			if( exp < 1 )
				printf( "%-30s  %6d    你已经完全体会了\n",
					to_chinese(s[i]) + " (" + s[i] + ")",
					my_tricks[s[i]] );
			else
				printf( "%-30s  %6d    %10d\n",
					to_chinese(s[i]) + " (" + s[i] + ")",
					my_tricks[s[i]], raise_cost( this_player(), s[i] ) );
		}
		write( "============================================================\n");
		return 1;
	}
	
	if( undefinedp( this_player()->query("tricks/"+arg) ) ) {
		write("这种计策你听都没听过，你可以用(study)研究研究过再来。\n");
		return 1;
	}
	if( raise_cost(this_player(), arg) == -2 ) {
	    write("对不起，这计策在这里只记录到这个级数。\n");
		return 1;
	}
	if( (exp = raise_cost(this_player(), arg)) < 1 ) {
		write("对不起，你对这个计策的体会还没有办法对它的运用方式有所改善。\n");
		return 1;
	}
	if( (int)this_player()->query_exp_stock() < exp ) {
		write("你现在要提高运用这个计策的能力，需要 "+exp+" 点经验。\n");
		return 1;
	}
	write("经过一番苦思之後，你对"+to_chinese(arg)+"的运用更加得心应手了！\n");
	this_player()->gain_experience( -exp );
	this_player()->add("tricks/"+arg, 1 );
	return 1;
}
