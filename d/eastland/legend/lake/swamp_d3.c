#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼泽地底洞穴");
    set_long(@LONG
咚的一声，你撞著了洞穴的顶部。你揉了揉弄痛的地方顺便环顾了一下四周，只
见前方一遍白茫茫的雾气，地面上是一颗一颗的大石头上面长著深绿色的青苔。越见
低矮的空间使你猜想前面应该没有通路了。
LONG
    );
    set("exits",([
            "north":LAKE"swamp_d1"
    ]) );
    set("objects",([
        "beholder":LMONSTER"beholder1"
    ]) );    
    ::reset();
}

