// File: 6,8.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("小溪");
	set_long( @LONG_DESCRIPTION
看来你还是受不了这清澈河水的召唤，悠游在其中是十分愉悦的事，
不过要注意两件事，第一、别忘了换气，第二、虽然可以游水、抓鱼，但
别污染环境喔！这小溪一路往西南流去。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,8.island", 
		"south" : ISLAND"6,9.island",
		]) );
	set( "original", ISLAND"6,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 8 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
     
