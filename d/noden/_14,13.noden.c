// File: /d/noden/14,13.noden.c
// Generated by Roommaker Tue Nov 21 00:30:02 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草地");
	ob->set_long( @LONG_DESCRIPTION
你现在走在一片绿油油的草地上，青翠的草地带著令人愉悦的
气息。几丛植物散布在碧绿的草地间，点缀著五彩缤纷的不知名野
花，使人心旷神宜。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/15,13.noden", 
		"west" : "d/noden/13,13.noden", 
		"north" : "d/noden/14,12.noden", 
		"south" : "d/noden/14,14.noden" ]) );
	ob->set( "objects", ([ 
		"toad" : "/d/noden/monster/toad" ]) );
	ob->set( "original", "d/noden/14,13" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 14 );
	ob->set( "y_coordinate", 13 );
	ob->reset();
}
