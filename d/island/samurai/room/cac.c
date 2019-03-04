#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "栅门" );
   set_long(@ANGEL
在你的面前是一个大的铁栅门，是要进入武士城堡必经之关卡，是武
士城堡交通的枢纽．
ANGEL

   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"cac02",
    "north" :MR"cac04"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","iron door"}),
                  "status"  : "closed",
                  "name"    : "Iron Door",
                  "c_name"  : "铁栅门",
                  "c_desc"  : "一个铁做的栅门\n"
                  ]) );
                            
         reset();                     
}

