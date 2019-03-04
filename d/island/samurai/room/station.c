#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "哨站" );
   set_long(@ANGEL
这里是武士城堡的入口前的一个哨站，是武士城堡防卫的第一线，但应属於观察
性质，所以看守的兵力并不多，往东走你可以离开武士城堡．    
ANGEL
   
         );
	set( "light",1);	
	set_outside("eastland");	
	set("objects",([
	    "guard1" :MOB"guard",
	    "guard2" :MOB"guard",
	    "soldier1" : MOB"soldier",
	    "soldier2" : MOB"soldier"
	    ])
	    );
        set( "exits", ([ 
   "north":MR"cac00",
   "east" :"/d/island/3,7.island"
                ]) );
         reset();                     
}

