// min1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿大厅");
    set_long(@C_LONG
这里是神殿的大厅，大理石地板上到处耸立著巨大的石柱，石柱上头密密
麻麻地刻著咒文，似乎是为了封印某种可怕的力量用的。难道这个神殿是用来
镇压妖魔用的？ 
C_LONG
    );
    set("exits", ([
	"south" : AREA"min0",
	"north" : AREA"min2",
	"east" : AREA"min1",
	"west" : AREA"min1"
	]) );
    reset();
}

