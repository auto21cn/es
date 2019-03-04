#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("山间狭道");
    set_long(@LONG
这是一条狭窄的通道，两旁是高耸的山壁，似乎随时会有落石崩下来一样，
不时传来不明的怪叫声，令人不寒而颤。东边似乎有座城！
LONG
            );
    set("exits",([
            "east":CITY"w1",
            "west":AREA"entrance",
            "northeast":AREA"way1",
            "southeast":AREA"way12"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
