#include "../megatower.h"

inherit ROOM;
inherit Megatower+"/daemon/trap";

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的内部");
  set_long(@Long
Long
,@CLong
这里位於是摩天塔的内部第一层的东边房间里的一个角落, 除了一些到处可见破碎
的瓦片与石块之外, 这里地上有一些小洞, 排列著很整齐的样子, 而且还冒著热气. 还
有一个阶梯, 通向摩天塔的第二层.
CLong
);
  set("exits",([
               "south" :Megatower"/floor1/63",
               "up"    :Megatower"/floor2/64",
             ]));

::reset();
}

void init()
{
     ::trap();
}
