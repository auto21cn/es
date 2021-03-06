#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp.c";

void create()
{
        ::create();
        set_short("沼泽");
        set_long( 
@LONG
你正走在一个泥泞的沼泽中，烂泥的臭味和泥浆里丑陋的植物令你忍不住一阵
作恶。这地带一直罕有人烟，甚至连一般的飞禽走兽也难觅其足迹。你现在站的地
方还只是沼泽的边界，趁你还没吸入过多沼气之前快离开吧。
LONG
    );
    set( "exit_suppress", ({
         "east","south","west" }) );
    set("exits",([
            "east":LAKE"swamp0",
            "south":LAKE"swamp2",
            "west":LAKE"swamp1"
       ]) );
    set("objects",([
          "mosquito#1":LMONSTER"mosquito",
          "mosquito#2":LMONSTER"mosquito"
         ]) ); 
    reset();
}

