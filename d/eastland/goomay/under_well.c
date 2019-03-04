#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "井里" );
        set_long(
@LONG
这是井里的一个小洞穴，绿色的井壁生满青苔，你很难想像在这
麽狭小的空间里竟然有人会在这里生活，但是地上明明摆\著一些食物
的残渣和灰烬。
LONG
        );
        
        set( "exits", ([
		"out"  : Goomay"ruin3",
        ]) );
        set( "objects", ([
                "prisoner" : Mob"prisoner",
		]));
        reset();
}
