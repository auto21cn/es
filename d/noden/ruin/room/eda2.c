// eda2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依达波第亚宫．宫门");
    set_long(@C_LONG
这里是依达波第亚宫的宫门，门楹上嵌著一颗斗大的水晶，隐隐约约地发
出一些黯淡的光芒，衬著那摇摇欲坠的石柱和基石，这地方想必也已然荒废了
一段很长的时间了。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda3" ]) );
    reset();
}

