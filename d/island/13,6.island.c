// File: 13,6.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("浅海");
	set_long( @LONG_DESCRIPTION
这儿是靠近岸边的的浅海，虽然深浅不一，但总在10公尺以内，海是
很危险的，随时要注意自己的身体状况，不要硬撑；唷！对了，这儿常有
暗潮，不小心可能会被冲得很远。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"12,6.island",
		"south" : ISLAND"13,7.island",
		]) );
	set( "original", ISLAND"13,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 13 );
	set( "y_coordinate", 6 );
        call_out( "flow_away",30 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory();
     i = sizeof( ob );
     
     while( --i>=0 )
     {  if( (int)ob[i] -> query( "likefish" ) < 1 )
        {
        tell_object(ob[i],"\n\n 哇！ 不妙，一股突如其来的海朝将你推到他处！ \n\n" );
        ob[i] -> move_player( ISLAND"12,5.island.c" ,"SNEAK" ) ;
        }   
     }
}     