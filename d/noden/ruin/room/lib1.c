// lib1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．长廊");
    set_long(@C_LONG
你现在身处於一条长长的走廊上，大理石铺成的走道向东方延伸。西方是一
面神奇的魔法壁，可以清楚地看见大厅内的情形。长廊的墙壁不知是用什麽东西
所建造的，闪耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib0",
	"east" : AREA"lib2"
	]) );
    set("light", 1);
    reset();
}


