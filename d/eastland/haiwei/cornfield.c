
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你现在正走在海威镇的南方的稻田里，此处现今是一片绿油油的稻草，风一吹来
草随风四处摇曳，不过此刻田中一片泥泞，走在此处你要万分小心以免溅的满身泥拧
。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/mroad4", 
                "south" : "/d/eastland/haiwei/cornfield1",
                "west" :  "/d/eastland/haiwei/cornfield2",
            "east" :  "/d/eastland/haiwei/cornfield3"
           ]) );
        reset();
}
