// File: 8,9.island.c

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
		"west"  : ISLAND"7,9.island", 
		"north" : ISLAND"8,8.island", 
		"east"  : ISLAND"9,9.island",
		"south" : ISLAND"8,10.island",
		]) );
	set( "original", ISLAND"8,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 9 );
	reset();
#include <replace_room.h>
}

