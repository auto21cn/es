#include "../tsunami.h"
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("河中");
    set_long(@LONG
在这潺潺的小河中看，只觉得一切都好乾净、好清晰，头顶上的光透过
波浪，映在底下的沙地上，使人感觉彷佛置身於尘嚣之外，那另一个未曾探
索过的世界一般。这令人流连的境地，让你几乎忘了要呼吸了！
LONG
            );
    set("exits",([
        "up":AREA"upriver1",
        "south":AREA"river"]) );
    set_outside("island");
    set("underwater",1);
    reset();
}

void init()
{
UNDERWATER->apply_effect(this_player(),3,2);
}
