// File: /d/eastland/saulin_temple/hallway13.c
// Generated by Roommaker Wed Nov 22 22:44:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("走廊");
	ob->set_long( @LONG_DESCRIPTION
你走在一条长廊上，两旁都是庭台堂芜，廊上僧人来往香客如织，挤的
根本没有心情去欣赏四周的环境少林寺号称千廊百院，像这样的长廊不知有
多少，你可得小心迷路。长廊向西方和北方延伸而去。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"west" : "/d/eastland/saulin_temple/hallway14", 
		"north" : "/d/eastland/saulin_temple/hallway12" ]) );
	ob->set( "objects", ([ 
		"monk" : "/d/eastland/saulin_temple/monster/gin_hwa" ]) );
	ob->reset();
}
