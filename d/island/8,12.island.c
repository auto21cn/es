// File: 8,12.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("海滩");
	set_long( @LONG_DESCRIPTION
这海滩的沙子是黄金色的，除此之外，夹杂在沙中的石英质，不断的
反著光线，一闪闪的，与蔚蓝海面上的粼煦波光，相映成趣。	
LONG_DESCRIPTION
	);
        
	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"8,11.island", 
		"east"  : ISLAND"9,12.island",
		"south" : ISLAND"8,13.island",
		]) );
	set( "original", ISLAND"8,12" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 12 );
	reset();
#include <replace_room.h>
}
