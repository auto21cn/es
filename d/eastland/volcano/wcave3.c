#include "oldcat.h"

inherit ROOM;

void create()
{
        ::create();
        set_short( "地道尽头" );
        set_long(
@LONG
你站在地道的尽头，一个小土阶往上通去，不必怀疑，上面就是出口了。
LONG
        );
	set( "exits", ([
        "up" : ONEW"varea5"
	]) );
        set("objects", ([
            "oregon":OMONSTER"oregon",
            ]) );
        reset();
#include <replace_room.h>
}
