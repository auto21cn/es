#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
啊！毒气，糟糕，你走进了最危险的沼泽地，四周都是足以致命的瘴气，而四
下的沼泽怪物更是对你虎视眈眈，随时都会扑过来，咬断你的咽喉，撕裂你的身躯
，吸食你的脑浆。啊，你一声惨叫，原来是一只腥红色的蜈蚣正狠狠的咬住你的左
脚，你慌慌张张的用力把它踹开，但四周愈来愈多奇奇怪怪的生物靠了过来，你现
在脑中只有一个想法，就是『逃命啊』！
LONG
    );
    set( "exit_suppress", ({
         "north","south","west","east" }) );
    set("exits",([
            "south":LAKE"swamp3",
            "north":LAKE"swamp1",
             "east":LAKE"swamp2",  
            "west":LAKE"swamp4"
       ]) );
    set("objects",([
         "centipede#1":LMONSTER"centipede",
         "centipede#2":LMONSTER"centipede"
         ]) ); 
    reset();
}

