// File: 5,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("车马道");
	set_long( @LONG_DESCRIPTION
这是蜿蜒在丘陵之中的道路，其实也不是刻意铺出来的，而是来往人
马将地面上踏出一条小路，路是人走出来的，这话还真是没错；这小路是
东西向的，通往武士堡。
LONG_DESCRIPTION
	);


	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,7.island", 
		"north" : ISLAND"5,6.island", 
		"east"  : ISLAND"6,7.island",
		"south" : ISLAND"5,8.island",
		]) );
	set( "original", ISLAND"5,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
