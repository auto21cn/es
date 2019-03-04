// File: /d/eastland/17,14.east.c
// Generated by Roommaker Wed Nov 22 13:11:11 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("沙滩");
	ob->set_long( @LONG_DESCRIPTION
你现在来到了海边的沙滩上，一望无际的大海在远处和碧蓝的天空相接，使
人忘却了烦恼。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"north" : "d/eastland/17,13.east" ]) );
	ob->set( "objects", ([ 
		"crab#1" : "/d/eastland/monster/crab", 
		"crab#2" : "/d/eastland/monster/crab" ]) );
	ob->set( "original", "d/eastland/17,14" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 17 );
	ob->set( "y_coordinate", 14 );
	ob->reset();
}
