//#pragma save_binary
 
//	File	:  /cmds/ghost/_inventory.c
//	Creator	:  Watcher@TMI  (4/11/93)
//
//	Yet another filler ghost command.

#include <mudlib.h>
 
inherit DAEMON ;
 
int cmd_inventory()
{
	write( can_read_chinese()?
		"你已经死了，那些身外之物「生不带来，死不带去」，忘了吧。\n":
		"You are a ghost ... you have nothing in your possession.\n");
	return 1;
}
 
