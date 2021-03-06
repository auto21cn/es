// File: 5,10.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("沼泽");
	set_long( @LONG_DESCRIPTION
在这沼泽中长了不少植物，尤其是原本该是泥水的地面，也被一些草
本植物盖满了，你走在这儿应该注意地面，否则会陷入泥沼，无法自拔。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,10.island", 
		"north" : ISLAND"5,9.island", 
		"east"  : ISLAND"6,10.island",
		"south" : ISLAND"5,11.island",
		]) );
	set( "original", ISLAND"5,10" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 10 );
	reset();
#include <replace_room.h>
}
