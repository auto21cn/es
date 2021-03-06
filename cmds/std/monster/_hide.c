////#pragma save_binary
#include <mudlib.h>
#define in_msg ({ "你找到一个阴暗的角落躲了起来。\n","你躲到桌子的下面。\n",\
		"你开始伪装成一座雕像。\n","你开始念 : 你看不到我 ... 你看不到我 ...\n",\
		"你把自己的眼睛蒙起来。\n","你贴在墙壁上，喃喃的念 : 我是壁花 ... 我是壁花 ...\n",\
		"你保持半蹲，假装是一张椅子。\n","你趴在地上, 动也不动。\n" })
#define out_msg ({ "你举起一支树枝，假装是一棵树。\n","你在头上插满青草，假装是草丛。\n",\
		"你蹲在地上，伪装成一颗大石头。\n","你蹑\手蹑\脚的躲到草丛里。\n",\
		"你找到一个阴暗的角落躲了起来。\n","你开始念 : 你看不到我 ... 你看不到我 ...\n",\
		})

inherit DAEMON;

int hide_idle(object me,int succeed)
{
	me->add_temp("hide_score",succeed);
	if ( environment(me)->query("outside") ) 
		me->quick_message(out_msg[random(sizeof(out_msg))]);
	else
		me->quick_message(in_msg[random(sizeof(in_msg))]);
	return 1;
}

int check_hide(object me)
{
	int base,r,skill;
	object attacker,ob;

	if ( attacker = me->query_attacker()  ) {
		ob = attacker->query_attacker();
		if ( (string)ob->query("name") == (string) me->query("name") )
			return -100;
	}
// 只跟 skill 有关 ....
	skill = (int) me->query_skill("hide") + (int) me->query("thief_level/backstab")/2;
	return (random(skill));
}

int cmd_hide()
{
	int score;
	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("你正在做其他事情 ...\n");
	write(set_color("你开始想办法躲躲藏藏 ...\n","HIY"));
	score = check_hide(this_player());
	if ( score < random(40) )
	tell_room(environment(this_player()),
			sprintf("%s开始到处躲躲藏藏 ...\n",this_player()->query("c_name"))
			,this_player() );

	this_player()->set_temp("next_action",time()+2);
	this_player()->set_temp("hidding",1);
	call_out("hide_idle",2,this_player(),score);
	return 1;
}

int help()
{
	write (@HELP
Usage: hide

这个指令能使你利用各种地形地物来隐藏自己，使得四周的人不再对你
对你有戒心，如果成功\的话，你将暂时从他们面前消失，直到你再次引
起他们的好奇心。如果你不怕附近的人笑你，多试几次是很有可能成功
的，但是要小心别人先下手为强。

HELP
);
	return 1;
}
