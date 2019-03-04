#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "城墙" );
   set_long(@ANGEL
你走在一个武士城堡的外围城墙的终点，这个位置正好是城门的上方，在
此可以攻击城门的敌人，所以为了战略的需求，这里也配有重兵力！！
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
	set( "objects", ([
	     "ekars" :MOB"ekars",
	     "guard1" :MOB"guard2",
	     "guard2" :MOB"guard2",
	          ]));
        set( "exits", ([
    "west" :MR"ca7",
                ]) );
         reset();                     
#include <replace_room.h>
}

