// lib3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．长廊");
    set_long(@C_LONG
你现在身处於一条长长的走廊上，大理石铺成的走道向东西方向延伸。两旁  
的墙壁上画著许多奇怪的图案，似乎是某种涂鸭。长廊的墙壁不知是用什麽东西
所建造的，闪耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib2",
	"east" : AREA"lib4"
	]) );
    set("item_desc", (["wall" : "墙上画著一个盾，笔法很是拙劣。\n"]) );
    set("light", 1);
    reset();
}


