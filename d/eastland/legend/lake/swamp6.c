#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
啊！毒气，糟糕，你走进了最危险的沼泽地，四周都是足以致命的瘴气。但是
奇怪的是，这里不像其他沼泽地充满各式各样吃人的巨型怪物，也没有人类的□骨
，相反的，这里到处都是巨型沼泽怪兽的残骸；虽然你已经站在这里好一段时间，
但却没有任何一只怪物追来。你四下搜寻，发现西边的空气中弥漫著一股浓厚的血
腥恶臭，这股恶臭比沼气更刺鼻，更难闻，而且每隔一段时间就传来一阵怪啸，声
音有如牛哞，但却远比其响亮。你想，一定是更恐怖的怪物。
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south" }) );
    set("exits",([
            "east":LAKE"swamp5",
            "north":LAKE"swamp3",
            "west":LAKE"swamp7",
            "south":LAKE"swamp3"
       ]) );
    reset();
}

