#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("产业道路");
    set_long(@LONG
这是一条铺满石板的产业大道，也是平时『津鸣城』对外联络的唯一途
径。两旁有篱笆树立著，藉以分隔道路和农田，避免因为人畜的不小心践踏
而损坏了宝贵的农作物；北边是『八哩八哩农场』的入口。
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"w3",
        "west":CITY"w1",
        "north":CITY"farm5"]) );
    reset();
#include <replace_room.h>
}
