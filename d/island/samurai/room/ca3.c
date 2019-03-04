#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "嘹望台" );
   set_long(@ANGEL
你走进一个嘹望台，这是武士城堡位置最高的地方，在这里可以清楚的看到
武士城堡的四周围状况，可说是最重要的预警系统，如果这里没有人看守的话，
那就算是敌人攻到眼前可能也无人发现．
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2"
	        ]) );
        set( "exits", ([
    "down"  :MR"ca1",
                ]) );
         reset();                     
#include <replace_room.h>
}

