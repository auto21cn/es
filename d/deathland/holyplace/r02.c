//Deathland/holyplace/r02.c
//Created by Echobomber Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","矮人圣地");
  set_long(@Long
Long
,@CLong
在这里你看到一些很大的建筑,而且四周充满著柔和的亮光,你已经到达矮人的圣地了.
一些破碎的运矿车被放置於地上,而南边有的柔软的墙壁,似乎用来降低碰撞的冲击力.
CLong
);
set("direction","block");
set("exits",([
             "north":Deathland"/holyplace/r01",
             ]));
reset();
}
