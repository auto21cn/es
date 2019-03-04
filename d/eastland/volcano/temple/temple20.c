#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿右殿");
	set_long( 
@LONG_DESCRIPTION
一间迷漫著神秘气氛的矮灵族神殿右殿，神殿的顶端雕有火龙的图案。
这里供奉的是火龙，在矮灵族的传说中火龙是火神的坐骑之一，火龙有时也
会幻成人形出现。你看到墙上的壁画描绘酒宴中的酋长，探险者，以及搬运
猎物的仆从，画面洋溢著安详和乐的气氛。
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple10",
     ]) );
set ("objects", ([
     "r_enforcer":OMONSTER"r_enforcer",
     "wprayer":OMONSTER"wprayer"
     ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
