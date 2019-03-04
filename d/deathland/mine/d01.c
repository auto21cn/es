
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big hole of Drawf mine ","矮人矿坑的大洞");
  set_long(@Long
Long
,@CLong
一个很黑很暗的大洞穴,曾经是个含量丰富的矿坑,但是自从传出这里出现怪物後
就没有什麽人敢来了.
CLong
);
set("direction","machine");
set("exits",([
             "up":Mine"/m63",
             "west":Mine"/d02",
             ]));
set("pre_exit_func",([
    "west":"to_west",
    ]) );
set("no_monster",1);
reset();
}

int to_west()
{
    write("当你往西走的时候,似乎一道隐形的力量横越在岩壁上.\n");
    return 0;
}
