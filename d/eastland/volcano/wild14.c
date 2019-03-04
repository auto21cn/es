#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long(
@LONG_DESCRIPTION
这片空地崎岖不平，到处都是红、黑色的石头，以及深褐色的土壤，你一看到这地
型地物就知道一定是火山爆发後的残留物，而且你也觉的这里蛮热的，你猜一定有火山
在这附近，远处似乎还传来阵阵鼓声，那猎人头族的部落一定也距离这里不远。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : ONEW"wild17",
     "southwest" : ONEW"wild11" ]) );
set( "objects", ([
     "adventurer":OMONSTER"adventurer" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
