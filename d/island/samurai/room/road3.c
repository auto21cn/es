#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "青石小径" );
   set_long(@ANGEL
你走在一个青石小径上，路面明显的比原来那条大道小很多，而且路面也改由青石
来铺成，沿著路走下去可以通往碉堡．    
ANGEL
   
         );
	set( "light",1);	
	set_outside("eastland");	
        set( "exits", ([
     "east" :MR"ca1",
     "west" :MR"road1",
                ]) );
         reset();                     
#include <replace_room.h>
}

