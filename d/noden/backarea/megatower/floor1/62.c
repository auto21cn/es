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
这里位於是摩天塔的内部第一层的东边房间里的一个角落, 除了一些到处可见破碎
的瓦片与石块之外, 这里地上有著营火, 似乎有著人类活动的迹像.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/63",
             ]));

::reset();
}

