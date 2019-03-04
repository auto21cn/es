#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("瀑布");
    set_long(@LONG
在这潺潺的小河上看，只觉得一切都好乾净，和风徐徐的吹著，天空偶
而有几只小鸟吱吱咂咂的飞过，难道这就是所谓的『世外桃源』吗？北边是
高大的山壁，西边有个十分壮观的瀑布，自上头冲了下来，形成一道美丽的
彩虹；东边有一片小沙岸．
LONG
            );
    set("exits",([
        "east":AREA"entrance1",
        "down":AREA"river1",
        "south":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

