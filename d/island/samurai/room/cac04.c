#include <mercury.h>

inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "亚瑟斯路" );
   set_long(@ANGEL
你走在亚瑟斯路上，这是一个宽广的大路，其路面是用坚硬的花岗石做的，道
路的北边是宽广的广场．    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac03",
                "north" :MR"cac05",
                ]) );
         create_door("south","north",([
                     "keyword" : ({"door","iron door"}),
                     "status"  : "closed",
                     "name"    : "Iron Door",
                     "c_name"  : "铁栅门",
                     "c_disc"  : "一个铁做的栅门\n"
                     ]) );       
         reset();                     
}

