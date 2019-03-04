#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
这片空地崎岖不平，到处都是黑色的石头，深褐色的土壤，你一看到这地型
地物就知道一定是火山爆发後的残留物，而且你也觉的这里蛮热的，你猜一定有
火山在这附近，而且那矮灵族的部落必定离这里不是很远。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"wild17" ]) );
set( "objects", ([
     "deadman":OMONSTER"deadman" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
