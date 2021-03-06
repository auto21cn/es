#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
        ::create();
        set_short("时空隧道");
        set_long( @C_LONG_DESCRIPTION
一个去白魔法城的时空隧道。
C_LONG_DESCRIPTION
        );

        set( "exits", ([ 
                "west" : "/d/mage/tower/white_lib", 
                "south" : "/d/mage/tower/time1" ]) );
        create_door( "west", "east", ([
                "keyword" : ({ "rusty iron door", "iron door", "door" }),
                "name" : "rusty iron door",
                "c_name" : "白魔法之门",
                "c_desc" : "一扇有魔力的白色门",
                "status" : "locked",
                "lock" : "1"
        ]) );
        reset();
}
