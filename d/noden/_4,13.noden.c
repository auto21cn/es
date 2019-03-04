// File: /d/noden/4,13.noden.c
// Generated by Roommaker Tue Nov 21 00:41:18 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("平原");
	ob->set_long( @LONG_DESCRIPTION
你现在走在一片平地上，疏落的青草点缀著一些碎石，这里开阔的视
野使你可以清楚地看到远方的景物。东边是魔法之都——摩亚达城。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/moyada/w_gate", 
		"west" : "d/noden/3,13.noden", 
		"north" : "d/noden/4,12.noden", 
		"south" : "d/noden/4,14.noden" ]) );
	ob->set( "original", "d/noden/4,13" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 4 );
	ob->set( "y_coordinate", 13 );
	ob->reset();
}
