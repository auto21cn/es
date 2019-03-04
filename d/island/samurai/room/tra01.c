#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士训练场入口" );
   set_long(@ANGEL
在你的面前是武士训练场的入口，里面则是所有武士团员都必须去的
地方，所有等级的武士都必须每天到此来上课及切磋武艺，由门内传出浓
浓的汗臭可以了解武士们苦练的辛苦．　
ANGEL

   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east" :MR"cac07",
    "west" :MR"tra02"
                ]) );
      create_door("west","east",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "木门",
                  "c_desc"  : "一个木头做的门\n"
                  ]) );
                            
         reset();                     
}

