//Deathland/holyplace/r03.c
//Created by Echobomber @Eastern.Stories

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
在这里你看到一些很大的建筑,虽然这些建筑没有甚麽美感,但是你能感觉到一种
严肃且庄重的气氛,四周充满著柔和的亮光,让人感到平安,祥和.你已经到达矮人的圣
地了.西南方有一处特别奇特的小屋,\或\许\你应该进去看看.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/r04",
             "east":Deathland"/holyplace/r01",
             "southwest":Deathland"/holyplace/h04",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();
}
