// File: /d/eastland/4,17.east.c
// Generated by Roommaker Wed Nov 22 13:15:00 1995

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

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/forest/0,2.forest", 
		"west" : "/d/eastland/forest/8,2.forest", 
		"south" : "/d/eastland/4,18.east", 
		"north" : "/d/eastland/4,16.east" ]) );
	ob->set( "no_monster", 1 );
	ob->set( "original", "d/eastland/4,17" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 4 );
	ob->set( "y_coordinate", 17 );
	ob->reset();
}
