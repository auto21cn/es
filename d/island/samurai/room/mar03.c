#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "市场警卫室" );
   set_long(@ANGEL
这是市场警卫所居住的地方，虽然有一点杂乱，但整体上大致还算乾
净，在墙角边放著一个武器架，而墙上则是记录著本月的物价情形．
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "guard1":MOB"market_guard",
    "guard2":MOB"market_guard"
            ]));			
        set( "exits", ([
   "south" :MR"mar02"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

