#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "市场" );
   set_long(@ANGEL
这里有是市场较为安静的角落，和前面的热闹比起来，这里显得
安静了很多，北边是一间旅店，而东边原本是是一间小商店但因经营
不善已倒闭．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar09",    
    "west" :MR"mar02",
                ]) );                   
         reset();                     
#include <replace_room.h>
}

