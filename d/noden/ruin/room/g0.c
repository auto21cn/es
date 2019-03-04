// g0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("废弃的花园");
    set_long(@C_LONG
你来到了一个废弃的花园，到处长满了杂草和青苔。这里弥漫著很重的湿
气，当然少不了那刺鼻的霉味无礼地刺激著你的嗅觉。杂草中似乎隐藏著一条
小径通往北方，「或许那儿的空气会比这里好一些」，你想。
C_LONG
	    );
    set("exits", ([ "north" : AREA"g1" ]) );
    reset();
}
