#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士训练场" );
   set_long(@ANGEL
你现在正在武士训练场内，四周摆了好几根击剑用的木头，还有几把练
习用的木刀摆在一旁，一股浓浓的汗臭味刺激著你的鼻子　
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "guard1" :MOB"guard",
    "guard2" :MOB"guard",
    "guard3" :MOB"guard"
              ]));		
        set( "exits", ([
    "north":MR"tra02",
                ]) );        
         reset();                     
#include <replace_room.h>
}

