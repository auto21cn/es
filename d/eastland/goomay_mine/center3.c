
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("矿坑大厅");
  set_long(@CLong
这是座十分宽阔的地方，有\许\多的矮凳子，可见此地是矿工们休息的地方，
而整个房间被开凿成八卦型，宛如蜘蛛网的中心点，是控制矿坑内各出口的重要
枢纽，要到达矿坑的任何角落，都必须经过此地．
CLong
);
   

set("exits",([
             "south":ZROOM"/center2",
             "northeast":ZROOM"/keyroom01",
             "west":ZROOM"/center4",
             ]));
set("objects",([
              "miner01" : ZMOB"/miner01",
              ]));

reset();
#include <replace_room.h>
}