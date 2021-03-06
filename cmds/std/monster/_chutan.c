
#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({
"一股真气由你的气海穴流出, 缓缓的流向背部的阳堂穴...\n",
"一缕\细微的真气经由督脉流向足三履穴, 却似忽遇到了阻碍而无法向前催动...\n",
"它强任它强, 清风过山岗... 我自一口真气足 千苦万苦也不苦... \n",
"........\n" 
});
void do_chutan( object player, int skill, int degree )
{
	int mana, max, dex, parry, block, dodge,level;

    tell_object( player, can_read_chinese(player)?
		"你感到...": "You see" );
	level =(int)player->query_level();
        if( degree < 10 && skill > random(degree * degree * 2+level) 
	&& (int)player->query("hit_points") > 20 ) {
		
                message("illusion", can_read_chinese(player)?
                        c_illusion[random(sizeof(c_illusion))]:
                        "you see some colorful illusions. \n", player);

                mana = (int)player->query("force_points");
		max = (int)player->query("max_fp");
		player->receive_damage(5);
		if( mana + degree * 3 > max )
			player->set("force_points", max );
		else
   		   player->set("force_points", mana + degree * 3 );
 		   call_out( "do_chutan", 3, player, skill, degree + 1 );
	} else {
	    player->set_temp("chutan", 0 );
	    if( !wizardp( player ) ) {
		  player->set_temp("block_command",0);
		  player->set_temp("block_message",0);
		  dex = player->query_perm_stat("dex");
	      parry = player->query_perm_skill("parry");
	      block = player->query_perm_skill("block");
	      dodge = player->query_perm_skill("dodge");
	      player->modify_stat("dex", dex);
	      player->modify_skill("parry", parry);
	      player->modify_skill("block", block);
	      player->modify_skill("dodge", dodge);
	    }
		  tell_object( player, "... 周遭的空气在流动著... 你体内的真气也不再聚集了...... \n");
		tell_object( player, 
	"你从清明之境返回这个纷扰的世界，你的运功\结束了。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "神清气爽地站了起来。\n",
			player );
	    call_out( "quit_chutan", degree*20, player );
	}
}

void quit_chutan( object player )
{
    player->set_temp( "layuter_chutan", 0 );
    tell_object( player, 
"你觉得丹田热烘烘的，一股内力从中涌出... 你又能运功\聚气了。\n" );
}

int cmd_chutan()
{
	int chu_skill, hp, dex, parry, block, dodge;

	chu_skill = (int)this_player()->query_skill("chutan");
	if( !chu_skill ) return notify_fail( "你没有学过聚丹功\，你不能使用它来聚集内力....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <35 ) return notify_fail( "你现在受伤过於严重，无法运功\.。\n" );
    if( this_player()->query_temp( "layuter_chutan" ) )
      return notify_fail( "你需要一段时间休息，才能有足够真气运功\..。\n");
	write( 
"你坐了下来, 默颂内功\心法, 将精神运至空灵之境... 你开始运功\聚气使真气运行全身。\n");
	tell_room( environment(this_player()), 
	this_player()->query("c_name")+ "盘腿而坐，开始运功\聚气...。\n",
		this_player() );
	this_player()->set_temp("chutan", 1 );
	this_player()->set_temp("layuter_chutan", 1 );
    if( !wizardp( this_player() ) ) {
	  this_player()->set_temp("block_command", 1 );
	  this_player()->set_temp("block_message", 1 );
	  dex = (int)this_player()->query_perm_stat("dex");
	  parry = (int)this_player()->query_perm_skill("parry");
	  block = (int)this_player()->query_perm_skill("block");
	  dodge = (int)this_player()->query_perm_skill("dodge");
	  this_player()->modify_stat("dex", -dex);
	  this_player()->modify_skill("parry", -parry);
	  this_player()->modify_skill("block", -block);
	  this_player()->modify_skill("dodge", -dodge);
	}
	call_out( "do_chutan", 2, this_player(), chu_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax: chutan

This command is to sit down and chutan. When you are chutaning, inner_force
points will recovery . How long you can chutan dependson your chutan skill.
Once you are awake from chutan, you'll have have some headache. But that's 
normal.
HELP
	);
    return 1;
}
