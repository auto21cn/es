//Deathland/holyplace/h03.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("mystic house","神秘小屋");
  set_long(@Long
Long
,@CLong
一处神秘的小屋,里面的东西杂乱无章,桌子上\摆\满了奇奇怪怪的瓶子,你无法了
解这个地方的人正在做甚麽.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h02",
             ]));
reset();
}
