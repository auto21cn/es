////#pragma save_binary

#include <mudlib.h>
inherit DAEMON;
int sneak_idle(object me,int succeed,string dir,string exit)
{
	string func;
	if ( (func = (string)environment(me)->query("pre_exit_func/"+dir)) && 
		call_other(environment(me),func) ) {
		me->delete_temp("block_command");
		return 1;
	}
	if ( succeed ) {
		me->set_temp("hidding",1);
		me->move_player(exit,"SNEAK");
		me->delete_temp("block_command");
		me->set_temp("hidding",0);
	} else {
		me->move_player(exit,"",dir);
        	this_player()->block_attack(4);
        	this_player()->set_temp("msg_stop_attack",
        	"( 你潜行失败，被敌人突袭，一阵手忙脚乱！ )\n" );
		call_out("sneak_done",2,me);
   	}	
	return 1;
}

int sneak_done(object me)
{
	me->delete_temp("block_command");
	return 1;
}
int check_sneak(object me)
{
	int skill;
	skill = (int)me->query_skill("sneak") ;
	if ( ! skill ) return 0;
//	if ( ! nullp(me->query_current_attacker()) ) return 0;
	skill += (10 + (int)me->query("thief_level/backstab")/2);
   	if ( skill > random(140) )
   		return 1;
   	else
   		return 0;
}
int cmd_sneak(string arg)
{
	string exit;
	mapping door;
	int delay;
	object env;

	env = environment(this_player()) ;

	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("你正在做其他事情 ...\n");
	if ( this_player()->query("conditions/confused") )
                return notify_fail(set_color("你觉得脑中一团混乱，好像有什麽不知名的东西在啃□著你...\n","HIM"));
	if ( ! arg ) return notify_fail("你要往哪里潜行？\n");
	if ( !exit = env->query("exits/"+arg) )
		return notify_fail("那里没有任何出路。\n");
	if ( door = env->query("doors/"+arg) )
		if ( (string)env->query("doors/"+arg+"/status") != "open" )
			return notify_fail("那里的门关著，你想穿过去吗？\n");
	/*
	if ( ! nullp(this_player()->query_current_attacker()) )
		return notify_fail("你还在战斗中, 无法潜行。");
	*/
	write(set_color(sprintf("你开始向%s潜行 ...\n",
			to_chinese(arg)),"HIY"));
/*  	既然是潜行, 应该不会大家都知道吧.
	tell_room(env,
		sprintf("%s开始向%s潜行 ...\n",this_player()->query("c_name"),
			to_chinese(arg)),this_player());
*/
	this_player()->block_attack(4);
	delay = 2 + random(4);
	this_player()->set_temp("hidding",0);
	this_player()->set_temp("next_action",time()+delay);
	this_player()->set_temp("block_command",1);
	call_out("sneak_idle",delay,this_player(),check_sneak(this_player()),
			arg,exit );	
	return 1;
}

int help()
{
	write (@HELP
Usage: sneak <dir>

这个指令能使你利用各种地形，隐秘的向期望的方向移动，这样你可以
在别人毫不知觉的情况下移动到他所在的位置，虽然这有点难，但是只
要成功\了，他就根本不能查觉你的存在。

HELP
);
	return 1;
}
