// eda6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依达波第亚宫．边厢");
    set_long(@C_LONG
这里是依达波第亚宫的边厢，到处散落著毁坏的石柱和瓦片，看来魔族一
定遭遇了极为可怕的灾难，才会造成这麽凄清的景象。这地方应该也已荒废了
一段很长的时间了。
C_LONG
    );
    set("exits", ([ "west" : AREA"eda4" ]) );
    reset();
}

