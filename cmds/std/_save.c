//#pragma save_binary

// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Written by Sulam(12-13-91)
// Help?? added by Brian on that most wonderful of days (1/28/92)

#include <mudlib.h>

inherit DAEMON;

int cmd_save(string str)
{
	object link ;
	this_player()->save_me();
	link = this_player()->query_link() ;
	if (link) link->save_data() ;
	write( 
		this_player()->query("c_name")+"资料存档....完毕。\n");

	return 1;
}

int help() {
	write(@HELP
Syntax: save

保存个人资料.
这里有定时保存用户资料功能，但为安全起见，建议升级后及时save.
HELP
);
	return 1;
}
/* EOF */
