#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "城墙" );
   set_long(@ANGEL
你走在一个武士城堡的外围城墙上，这个城墙很高，当你试著从城墙边往
下看时，你会有一股心里毛毛的感觉，因为城墙实在太高了，城墙向东西边延
伸．
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
        set( "exits", ([
    "west" :MR"ca6",
    "east" :MR"ca8",
                ]) );
         reset();                     
#include <replace_room.h>
}

