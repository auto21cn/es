#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "亚瑟斯路" );
   set_long(@ANGEL
你走在亚瑟斯路上，这是一个宽广的大路，其路面是用坚硬的花岗石做的，而
道路的两旁各有一个像是碉堡一个的建筑，而这条道路向北延伸．    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac00",
                "north" :MR"cac02",
                ]) );
         reset();                     
#include <replace_room.h>
}

