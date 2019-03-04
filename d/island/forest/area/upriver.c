#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("河流");
    set_long(@LONG
在这潺潺的小河上看，只觉得一切都好乾净，和风徐徐的吹著，天空偶
而有几只小鸟吱吱咂咂的飞过，难道这就是所谓的『世外桃源』吗？
LONG
            );
    set("exits",([
        "east":AREA"entrance",
        "down":AREA"river",
        "north":AREA"upriver1",
        "south":AREA"upriver2"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

