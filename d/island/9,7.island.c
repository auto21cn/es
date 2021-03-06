// File: 9,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("林荫道");
	set_long( @LONG_DESCRIPTION
这位在森林中的道路是魔族所造的，由石板铺成的路面，笔直的在树
林中穿过，两旁的树木正好把阳光滤掉，走在这儿你觉得十分凉爽；东西
向的林荫道，连接了映世村和津鸣城。
LONG_DESCRIPTION
	);



	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,7.island", 
		"north" : ISLAND"9,6.island", 
		"east"  : ISLAND"10,7.island",
		"south" : ISLAND"9,8.island",
		]) );
	set( "original", ISLAND"9,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 7 );
	reset();
#include <replace_room.h>
}
