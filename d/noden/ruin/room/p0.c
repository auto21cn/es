// p0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("卡榭布兰卡宫．门厅");
    set_long(@C_LONG
眼前所见是一片美丽的景象，娇艳的香水百合映著巍峨的廊柱，空气中充
满著馥郁的香气，以及蝴蝶翩翩飞舞的身影。在这里，你顿时觉得心情舒畅不
已。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"p1"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write("别找啦，你过关啦，女王的寝宫不是让你逛大街的地方 :p\n");
    return 1;
}

