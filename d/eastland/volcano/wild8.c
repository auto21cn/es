#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("草地");
	set_long( 
@LONG_DESCRIPTION
这里没有明显的路给你走，你站在一大片草地中间，草地呈黄绿色，每当有风吹
过，所有的草就随风左右摇曳，如同海浪一般，仔细观察地面似乎有几个小地洞，可
能是土拨鼠之类的动物，在这里建造它们的房子；在这危险的地方，风声鹤唳，稍微
有点风吹草动，都会使人惊心胆颤。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : ONEW"wild7",
     "southeast" : ONEW"wild11", ]) );
set( "objects", ([
     "worm":OMONSTER"worm",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
