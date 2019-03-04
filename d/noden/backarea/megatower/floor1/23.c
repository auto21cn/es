#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的内部");
  set_long(@Long
Long
,@CLong
这里是摩天塔的内部第一层, 这塔似乎是年久失修, 到处可见破碎的瓦片与石块,
还有著一些奇奇怪怪的足迹印在地上. 这地方由於终年不见阳光, 显得十分的阴暗潮湿
. 慢慢地你觉得塔内的空气越来越糟糕, 还有一股肃杀的气氛向你渐渐地逼近. 一种忽
远忽近有节奏的怪怪的声音从塔的正中央传出, 你完全不能理解这个奇怪的高塔. 东边
有著一根巨大的柱子挡著你的路, 你发觉怪声是从柱子内传出来的.
CLong
);
  set("exits",([
               "west"  :Megatower"/floor1/13",
               "north" :Megatower"/floor1/24",
               "south" :Megatower"/floor1/22",
             ]));

::reset();
}
