
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
  set_short("well","地下河道");
  set_long(@Long
Long
,@CLong
四周到处都是青苔和一些奇怪的小虫,而且这里的泥土十分潮□,似乎这里是地下
河川的河道,但是目前这河道已经乾\枯\了\.南边的岩壁上有著一个细细的狭缝,勉强你
可以挤过去.
CLong
);

set("exits",([
     "northwest":Deathland"/dwarf/well04",
     "southeast":Deathland"/dwarf/well07",
     "south":Deathland"/dwarf/pass01.c",
     ]) );
set("pre_exit_func",([
    "south":"to_south",
    ]) );     
 ::reset();
}

int to_south()
{
    write("你用力地挤过去这个细缝後,你的人似乎有著腾空的感觉.看一看地面\n"
          "啊!离地竟然有五六尺.\n\n\n\n\n咻...............\n砰的一声,你整个人跌了下来\n"
         );
    return 0;  
}
