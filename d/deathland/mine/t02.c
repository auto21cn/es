
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("On the Stair","阶梯上");
  set_long(@Long
Long
,@CLong
你注意到你正站在阶梯上, 这是一个东西向的阶梯.  
CLong
);
set("exits",([
             "westup":Mine"/t03",
             "eastdown":Mine"/t04",
             ]));
#include <replace_room.h>
}
