// File: 10,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("树海");
	set_long( @LONG_DESCRIPTION
这是一片由高耸入云的巨木所构成的树海，由於树木很密，致使你几
乎看不到树林深处有什麽存在，也因此这里从以前就有很多神秘的传说。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"9,5.island", 
		"north" : ISLAND"10,4.island", 
		"east"  : ISLAND"11,5.island",
		"south" : ISLAND"10,6.island",
		]) );
	set( "original", ISLAND"10,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 5 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

