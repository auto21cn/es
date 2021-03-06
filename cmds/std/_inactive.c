//#pragma save_binary
 
//	File	:  /cmds/std/_inactive.c
//	Created :  Watcher@TMI  (09/27/92)
//
//	Command to toggle user inactive mode.
 
#include <mudlib.h>

inherit DAEMON;

int cmd_inactive()
{
	object me;

	me = this_player();
	write("你决定暂停活动. 请按 [ENTER] 以继续活动.\n");
	tell_room(environment(me), 
		sprintf("%s(%s)决定暂时停止活动。\n", me->query("c_name"),
			me->query("name")) , me);

	me->set("inactive", time());
 
	input_to("stop_inactive", 1);

	return 1;
}

int stop_inactive()
{
	object me;

	me = this_player();
	printf("你在停止活动 %s 後又开始活动.\n",
		format_time(time()-(int)me->query("inactive"), 1));
	tell_room(environment(me), 
		sprintf("%s(%s)又开始重新活动了。\n", me->query("c_name"),
			me->query("name")) , me);
	me->delete("inactive");
	return 1;
}
 
int help()
{
	write(@HELP

这个指令使你处于停止不动状态.

HELP
);
	return 1;
}

// Prevent cleanup.
int clean_up()
{
	return 1;
}
