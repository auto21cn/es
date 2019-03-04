#include "../megatower.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的内部");
  set_long(@Long
Long
,@CLong
这里是摩天塔的内部第一层西边的一个房间, 这塔似乎是年久失修, 到处可见破
碎的瓦片与石块, 还有著一些奇奇怪怪的足迹印在地上. 这地方由於终年不见阳光, 
显得十分的阴暗潮湿. 慢慢地你觉得塔内的空气越来越糟糕, 还有一股肃杀的气氛向
你渐渐地逼近.  
CLong
);
  set("objects",([
      "goblin#01":Monster"/goblin01",
      "goblin#02":Monster"/goblin01",
      "goblin#03":Monster"/goblin01",
      ]) );
  set("exits",([
               "east" :Megatower"/floor1/13",
               "south":Megatower"/floor1/02",
               "north":Megatower"/floor1/04",
             ]));
  create_door("east","west",([
             "name":"stone door",
             "c_name":"石门",
             "keyword":({"stone door","door",}),
             "c_desc":"石门",
             "status":"closed",
             "desc":"a stone door",
                     ]) );

::reset();
}
