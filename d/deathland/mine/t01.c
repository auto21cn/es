
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("Mine","矿坑的深处");
  set_long(@Long
Long
,@CLong
这里是矿坑的深处. 北边有一堆乱石把通道给堵住了, 目前除了南边的一个
窄窄的裂缝, 你没有任何的出路. 
CLong
);
set("direction","block");
set("exits",([
             "south":Mine"/t02",
             ]));
#include <replace_room.h>
}
