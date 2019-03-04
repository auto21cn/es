// min0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿入口");
    set_long(@C_LONG
这里是个神殿的入口，四周冷冷清清地，不但没有庄严神圣的气氛，反倒
令人觉得有些阴森恐怖。从这里往神殿里看去，尽是一片黑暗，看来如果想要
找到出口的话，只有硬著头皮往前走了。
C_LONG
    );
    set("exits", ([ "north" : AREA"min1" ]) );
    reset();
}


