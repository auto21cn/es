#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "林间小径" );
   set_long(@ANGEL
你走在樱花树林中的小径上，道路的两旁都是盛开的樱花树，飘落的樱花在
你面前飞舞著，构成一幅美丽的景色，也不知道他们是怎麽种的，这些樱花树居
然能保持四季都开著花，或许这是一种东方的神秘吧！
ANGEL

   
         );
	set_outside("eastland");		
        set( "exits", ([
    "east"  :MR"tree05",
    "north"  :MR"tree04",
    "south"  :MR"tree07"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

