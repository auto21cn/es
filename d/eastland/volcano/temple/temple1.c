#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("矮灵族神殿");
	set_long(
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿，这里是正殿，正殿的顶端雕有火神的图案，
四根雕有龙纹的巨大柱子竖在四个脚落，前面似乎有一些人在那儿，距离太远了
你看不清楚他们在做什麽，也不知道这个正殿供奉什麽神。
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple4",
     "east": OTEMP"temple3",
     "west": OTEMP"temple2",
     "out" : OGROUP"warea16",
     ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
