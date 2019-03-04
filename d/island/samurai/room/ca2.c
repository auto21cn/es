#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "碉堡" );
   set_long(@ANGEL
你走进一个小型的碉堡，四周围的墙壁都是用见坚硬的石块所筑成的，拥
有完善的防御力，里面还有一个楼梯可以通往嘹望台．
ANGEL
   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east"  :MR"road4",
    "up"  :MR"ca4",
                ]) );
         reset();                     
#include <replace_room.h>
}

