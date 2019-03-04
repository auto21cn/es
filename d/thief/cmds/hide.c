//#pragma save_binary
#define RATE ({ 0,5,20,32,41,47,50,53,59,68,80,95, })

#include <mudlib.h>

inherit DAEMON;

int hide_idle(object me,int succeed)
{
	me->set_temp("hidden",0);
// 不设 hidding = 0 ; 使 hiden 的成功率有累加的效果
//	me->set_temp("hidding",0);  
//	tell_object(me, (succeed ) ? "succeed\n": "fault\n" );
	if ( succeed ) 
		me->set_temp("hidding",1);
	return 1;
}
int check_hide(object me)
{
	int iq,dex,kar,rate,level;
	object attacker,ob;

	if ( (attacker = me->query_attacker())  ) {
		ob = attacker->query_attacker();
		if ( (string)ob->query("name") == (string) me->query("name") )
			return 0;
	}
/*
	level = (int)me->query_level();
//	level = (int)me->query_skill("hide")/5 ;
	iq = (int)me->query_stat("int");
	dex = (int)me->query_stat("dex");
	kar = (int)me->query_stat("kar");

//	kar += kar+dex+iq;
//	rate = level*level/6 + (kar+kar+dex+iq)/2 ;
	rate = level*level/8 + ( 2*kar+3*dex+3*iq )/2;
	rate = rate * (int)me->query_skill("hide")/100 ;
// level bonus
// 每五级加成功率 3
	rate += 3*(level+2)/5 ;
	rate = ( rate > 95 ? 95 : rate );
//   level -> 60 % for level 19
//	 attrs -> 45 % for full 
*/
// 只跟 skill 有关 ....
   	if ( random( 90 ) < (int)me->query_skill("hide")  )
   		return 1;
   	else
   		return 0;
}
int cmd_hide()
{
	if ( this_player()->query_temp("hidden") )
		return notify_fail("你正在到处躲躲藏藏 ...\n");
	write(set_color("你开始到处躲躲藏藏 ...\n","HIY"));
	tell_room(environment(this_player()),
			sprintf("%s开始到处躲躲藏藏 ...\n",this_player()->query("c_name"))
			,this_player() );
	this_player()->set_temp("hidden",1);
	call_out("hide_idle",3,this_player(),check_hide(this_player()));
	return 1;
}

int help()
{
	write (@HELP
Usage: hide

这个指令能使你利用各种地形地物来隐藏自己，使得四周的人不再对你
对你有戒心，如果成功\的话，你将暂时从他们面前消失，直到你再次引
起他们的好奇心。

HELP
);
	return 1;
}
