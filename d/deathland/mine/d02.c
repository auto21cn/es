
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人矿坑的大洞穴");
  set_long(@Long
Long
,@CLong
一个很黑很暗的大洞穴,曾经是个含量丰富的矿坑,但是自从传出这里出现怪物後
就没有什麽人敢来了.越往西走,就觉得似乎有人在窥探你的样子.
CLong
);
set("exits",([
             "west":Mine"/d03",
             "east":Mine"/d01",
             ]));
set("pre_exit_func",([
    "east":"to_east",
    ]) );
reset();
}

int to_east()
{
    write("当你往东走的时候,似乎一道隐形的力量横越在岩壁上.\n");
    return 0;
}
