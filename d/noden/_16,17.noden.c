// File: /d/noden/16,17.noden.c
// Generated by Roommaker Tue Nov 21 00:32:44 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("沼泽");
	ob->set_long( @LONG_DESCRIPTION
你现在正走在一个泥泞的沼泽中，乌黑的烂泥夹带著令人作呕
的臭味令你不得不掩住鼻子，泥浆中不少深绿色的植物及藤蔓互相
交错纠葛，一些高大植物的顶端开著不少诡异的白花。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/17,17.noden", 
		"west" : "d/noden/15,17.noden", 
		"north" : "d/noden/16,16.noden", 
		"south" : "d/noden/16,18.noden" ]) );
	ob->set( "objects", ([ 
		"brownie" : "/d/noden/monster/swamp_brownie" ]) );
	ob->set( "original", "d/noden/16,17" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 16 );
	ob->set( "y_coordinate", 17 );
	ob->reset();
}
