// File: 11,5.island.c

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
		"west"  : ISLAND"10,5.island", 
		"north" : ISLAND"11,4.island", 
		"east"  : ISLAND"12,5.island",
		"south" : ISLAND"11,6.island",
		]) );
	set( "original", ISLAND"11,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 5 );
        set( "no_monster", 1 );
        set( "objects" , ([ 
                "t1":IMON"turtle2",
                "t2":IMON"turtle2",
                "t2":IMON"turtle1"
                ]));
	reset();
}
