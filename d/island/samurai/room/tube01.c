#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "地下水道" );
   set_long(@ANGEL
你来到一个地下水道，虽然是在地下，但空气却是很清新，让你不会
有气闷的感觉，而且你发现这里地上蛮乾净的，似乎有人居住在里面．    
ANGEL
   
         );
	set( "light",0);
        set( "exits", ([
                "south":MR"tube01",
                "west" :MR"tube03"
                ]) );
         reset();                     
#include <replace_room.h>
}

