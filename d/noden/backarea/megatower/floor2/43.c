#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","摩天塔的二楼走廊");
  set_long(@Long
Long
,@CLong
你到达了摩天塔的第二层, 这里到处可见破碎的瓦片与石块. 曲曲折折的回廊
是这层的特色, 每个转角你都必须小心陷阱, 莫名的怪物也将躲在角落处等著偷袭
你.  
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/42",
               "east"  :Megatower"/floor2/53",
               "north" :Megatower"/floor2/44",
             ]));

::reset();
}

