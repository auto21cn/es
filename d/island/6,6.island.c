// File: 6,6.island.c

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
别污染环境喔！这小溪一路往西北流去。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,6.island", 
		"north" : ISLAND"6,5.island", 
		]) );
	set( "original", ISLAND"6,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 6 );
        set( "objects" , ([
                  "fish #1" : IMON"s_fish.c",
                  "fish #2" : IMON"s_fish.c"
                         ]) );     
        call_out( "flow_away",30 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory( );
     i = sizeof( ob );
     
     while( --i>=0 )
     {  
        if( (int)ob[i] -> query ( "likefish" ) < 1 ) 
        {
        tell_object( ob[i],"\n\n 哇！ 你被水流走啦～～～～～～～ 唷呵！ \n\n" );
        ob[i] -> move_player( ISLAND"5,5.island.c" ,"SNEAK") ;
        }
     }
}     
