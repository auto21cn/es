#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("河流");
    set_long(@LONG
在这潺潺的小河上看，只觉得一切都好乾净，和风徐徐的吹著，天空偶
而有几只小鸟吱吱咂咂的飞过，难道这就是所谓的『世外桃源』吗？南面和
西面都是高耸的山壁，令你不解的是：这河流怎麽没出口了还会流？东边的
沙岸上长著一棵非常茂密的大树！
LONG
            );
    set("exits",([
        "east":AREA"entrance2",
        "down":AREA"river2",
        "north":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

