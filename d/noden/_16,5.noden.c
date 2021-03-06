// File: /d/noden/16,5.noden.c
// Generated by Roommaker Mon Nov 20 14:39:47 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("森林");
	ob->set_long( @LONG_DESCRIPTION
你现在漫步在一座森林之中，繁茂的树木散发出一股淡淡的、
舒爽宜人的气息，但是这里却出奇地安静，听不到树林间鸟叫声，
脚底下一层落叶铺满了你所站立的地方。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/17,5.noden", 
		"west" : "d/noden/15,5.noden", 
		"north" : "d/noden/16,4.noden", 
		"south" : "d/noden/16,6.noden" ]) );
	ob->set( "objects", ([ 
		"crow" : "/d/noden/monster/spec_crow" ]) );
	ob->set( "original", "d/noden/16,5" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 16 );
	ob->set( "y_coordinate", 5 );
	ob->reset();
}
