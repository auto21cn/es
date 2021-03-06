// File: 7,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("桃林小径");
	set_long( @LONG_DESCRIPTION
这是蜿蜒在桃花林中的泥土小径，路上布满了落下来的桃花，清新的
空气加上悦耳的鸟鸣，还有两旁的桃花林，使走在这儿成了最佳享受；这
小径虽然不是很直，但是大致上还是由南向北延伸的。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
	        "west"  : ISLAND"6,5.island",
		"north" : ISLAND"7,4.island",
		"east"  : ISLAND"8,5.island", 
		"south" : ISLAND"7,6.island",
		]) );
	set( "original", ISLAND"7,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}
