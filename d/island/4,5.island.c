// File: 4,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("小丘陵");
	set_long( @LONG_DESCRIPTION
这起伏不大的丘陵上长满了嫩绿的鲜草，而点缀其上的小白花，使这
里令人觉得精神愉快，站在这儿可以看到远方的大海，这是因为这里都没
有高大的植物。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"3,5.island", 
		"north" : ISLAND"4,4.island", 
		"east"  : ISLAND"5,5.island",
		"south" : ISLAND"4,6.island",
		]) );
	set( "original", ISLAND"4,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 4 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}
