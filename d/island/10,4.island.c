// File: 10,4.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("溪口");
	set_long( @LONG_DESCRIPTION
小溪流到这儿就到大海了，在这儿也比上游深多了，所以要特别小心
啊！当然这儿跟海比来是要好多了。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"9,4.island", 
		"north" : ISLAND"10,3.island", 
		"east"  : ISLAND"11,4.island",
		"south" : ISLAND"10,5.island",
		]) );
	set( "original", ISLAND"10,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 4 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 4, 1 );
}
