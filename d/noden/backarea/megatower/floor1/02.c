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
这里位於是摩天塔的内部第一层的西边房间里的一个角落, 除了一些到处可见破碎
的瓦片与石块之外, 还有著一些航海用的大水桶堆与此地.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/03",
             ]));

::reset();
}
