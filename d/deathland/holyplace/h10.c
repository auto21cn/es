// Deathland/holyplace/h10.c
// Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","阴暗的虚无飘渺处");
  set_long(@Long
Long
,@CLong
一处阴暗的地下世界,四处的黑影无声无息地向你侵袭而来.这里的寂静令人感到害怕,
让你不自主的想要发出一些声音.没有风声,没有水声,甚至你无法听到自己的脚步声,你不
禁怀疑自己处在一个虚无的地方.你的视野越来越小,似乎你的眼睛被一些黑色的\"雾\"挡住
了视线.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "north":Deathland"/holyplace/h07",
             "south":Deathland"/holyplace/h14",
             ]));
reset();
}

string to_look_fog()
{
     return can_read_chinese() ?
            "是雾吗?你怀疑著,你能很清楚地看到一些悬浮粒子飘散在你的周围.\n"
            "\或\许\是一种邪恶的物质,你能感觉到有著邪恶的成份参杂其中.\n" :
            "need work.\n"; 
}
