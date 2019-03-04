
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("strange fog","奇怪的雾里");
  set_long(@Long
Long
,@CLong
在这里你只见雾越来越大了, 然而西边的红色火团却很明显, 从这里你就能感
受到那团火的妖气. 究竟那是什麽呢? 
CLong
);

set("exits",([
             "east":Deathland"/holyplace/h21",
             "west":Deathland"/holyplace/h24",
             ]));
reset();
}
