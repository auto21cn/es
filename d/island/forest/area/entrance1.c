#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","河滨");
    set_long(@LONG
展现在眼前的是一片高耸的山壁，平时由远处就能看得见，旁边还有一
条清澈的小河流，大概是因为人烟稀少的关系，这条小河还得以维持原来的
风貌。
LONG
             );
    set("exits",([
            "south":AREA"entrance",
            "west":AREA"upriver1"]) );
    set_outside("island");
     reset();
#include <replace_room.h>
}
