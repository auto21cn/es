#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","摩天塔的二楼");
  set_long(@Long
Long
,@CLong
你到达了摩天塔的第二层,  这里到处可见破碎的瓦片与石块. 往南有个走廊,通往塔
的深处. 还有一个阶梯, 向下通向摩天塔的底层.
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/63",
               "down"    :Megatower"/floor1/64",
             ]));

::reset();
}

