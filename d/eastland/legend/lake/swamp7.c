#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
object toad;
        ::create();
    set_short("沼泽");
        set_long( 
@LONG
啊！毒气，糟糕，你走进了最危险的沼泽地，四周都是足以致命的瘴气。但是
奇怪的是，这里不像其他沼泽地充满各式各样吃人的巨型怪物，也没有人类的□骨
，相反的，这里到处都是巨型沼泽怪兽的残骸。莫名的肃静，空气中除了弥漫著一
股浓厚的血腥恶臭之外，更有一种令人毛骨悚然，心惊肉跳的感觉；一种似乎你已
经不是活人的感觉。
LONG
    );
    set( "exit_suppress", ({
        "east","south","west","north","southwest" }) );
    set("exits",([
            "east":LAKE"swamp6",
            "west":LAKE"swamp4", 
           "south":LAKE"swamp2",
           "north":LAKE"swamp5",
       "southwest":LAKE"swamp8",
       ]) );
       toad = new(LMONSTER"redtoad");
       toad->move(this_object());
        
       reset();
}
int clean_up()
{
       return 0;
}

