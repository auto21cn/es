// File: 5,6.island.c

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
		"west"  : ISLAND"4,6.island", 
		"north" : ISLAND"5,5.island", 
		"east"  : ISLAND"6,6.island",
		"south" : ISLAND"5,7.island",
		]) );
	set( "original", ISLAND"5,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 6 );
	reset();
#include <replace_room.h>
}
