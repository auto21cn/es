// File: /d/noden/moyada/shop/strange_room.c
// Generated by Roommaker Tue Dec  5 19:29:44 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("奇怪的房间");
	ob->set_long( @LONG_DESCRIPTION
你很讶异这里竟有这样的一个房间，漂亮的装饰品布满了四周，这里的主人
一定十分有气质。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/noden/moyada/shop/hole" ]) );
	ob->set( "objects", ([ 
		"girl" : "/d/noden/moyada/monster/little_girl" ]) );
	ob->reset();
}
