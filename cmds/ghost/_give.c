//#pragma save_binary
 
//	File	:  /cmds/ghost/_give.c
//	Creator	:  Watcher@TMI  (4/11/93)

//
//	Yet another Ghost filler command

#include <mudlib.h>

inherit DAEMON ;
 
int cmd_give()
{
	write( can_read_chinese()?
		"你已经死了，身上什麽也没有。\n":
		"Alas, as a ghost, you have nothing to give.\n");
	return 1;
}
 
