#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "旅店二楼" );
   set_long(@ANGEL
这里是旅店二楼的一个小房间，由是在二楼，由日光射入，采光较
一楼好多了，窗户旁种有一些花朵．　
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "nakoruru":MOB"nakoruru",
    "eagle"   :MOB"eagle"
           ]));			
        set( "exits", ([
    "down":MR"mar09",    
                ]) );                   
         reset();                     
}

