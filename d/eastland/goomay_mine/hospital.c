
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("清境");
  set_long(@CLong
一阵浓郁的药草味扑鼻而来，可见此地是矿工们疗养治病的地方，一张张
\摆\设整齐且乾净的床铺，的确是一个休息的好地方，与外面乌漆吵杂的环境迥
然不同．
CLong
);
   

set("exits",([
             "east":ZROOM"/center1",
             ]));
set("objects",([
             "invalid":ZMOB"/invalid.c"
             ]));
             reset();
#include <replace_room.h>
             }