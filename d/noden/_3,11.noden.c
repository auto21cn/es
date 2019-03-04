// File: /d/noden/3,11.noden.c
// Generated by Roommaker Tue Nov 21 00:40:17 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("森林");
	ob->set_long( @LONG_DESCRIPTION
你现在漫步在一座森林之中，繁茂的树木散发出一股淡淡的、
舒爽宜人的气息，你可以听到树林间小鸟吱吱喳喳的鸣叫声，脚底
下一层落叶铺满了你所站立的地方。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/4,11.noden", 
		"south" : "d/noden/3,12.noden" ]) );
	ob->set( "original", "d/noden/3,11" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 3 );
	ob->set( "y_coordinate", 11 );
	ob->reset();
}
