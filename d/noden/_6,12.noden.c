// File: /d/noden/6,12.noden.c
// Generated by Roommaker Tue Nov 21 00:43:55 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("山丘");
	ob->set_long( @LONG_DESCRIPTION
你正走在一由一些低矮山丘组成的丘陵地上，这里的地势起伏
并不很大，青黄交错的短草皮覆盖著举目所及的山丘，几株大树散
布在山坡上。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"south" : "d/noden/6,13.noden", 
		"north" : "d/noden/6,11.noden", 
		"west" : "d/noden/5,12.noden" ]) );
	ob->set( "original", "d/noden/6,12" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 6 );
	ob->set( "y_coordinate", 12 );
	ob->reset();
}
