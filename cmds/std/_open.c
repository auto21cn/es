//#pragma save_binary

// open.c
// Lets players open doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Opening containers is handled by an add_action in the container, not by
// this command.
// Updated by Watcher@TMI-2 (03/28/93) to handle "open door".
// Watcher@TMI added vision checks (04/13/93).

#include <mudlib.h>

inherit DAEMON ;

int cmd_open (string str)
{
	string dir, *tmp;
	object env ;
	mapping doors ;

	if(!str || ( str!="door" && !(dir=environment(this_player())->query_door(str)) 
	&& sscanf(str,"%s door", dir) != 1))
		return notify_fail( 
			"你要打开甚麽东西？\n");

	env = environment(this_player());
	if (!env)
		return notify_fail( 
			"这里甚麽也没有，你要打开甚麽东西？\n");

	doors = env->query("doors") ;
 
	if (!doors)
		return notify_fail( 
			"这里没有门....。\n");
 
	tmp = keys( doors );
 
	if(str == "door") {
		if(sizeof(doors) > 1)
			return notify_fail( 
				"这里的门不只一个，你要开哪一个？\n");

		dir = tmp[0];
	}
 
	//  If the user can't see ... then pick a random door. <grin>
	if(!this_player()->query("vision"))  {
		write( 
			"你在黑暗中摸索，找门....。\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if (!doors[dir])
		return notify_fail(
			"这个方向没有门....。\n");

	if (doors[dir]["status"]=="open")
		return notify_fail( 
			"它已经被打开了。\n");

	if (doors[dir]["status"]=="locked")
		return notify_fail( 
			"咦....打不开，大概是锁住了。\n");

	env->set_status(dir, "open");
	env->update_link(dir);
	printf( "你把%s打开。\n", doors[dir]["c_name"] );

	tell_room( env, 
		this_player()->query("c_name")+"打开了"+ doors[dir]["c_name"] + ".\n" ,
		this_player()
	);
	return 1 ;
}

int help() {
	write (@HELP
使用格式: open <方向> door  -or-  open <容器>

这个指令可以打开关闭的门或容器，但它必须是没有锁上的.

相关指令: get, put, close, lock, unlock.
HELP
	) ;
	return 1 ;
}
