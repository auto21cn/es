// g7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("废弃的花园");
    set_long(@C_LONG
你来到了一个废弃的花园，到处长满了杂草和青苔。这里的空气充满著肃
杀的气氛，似乎连你身上的血液也快要为之凝结起来。杂草中似乎隐藏著一个
什麽东西，但是你看不清楚。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g9",
	"east" : AREA"g8",
	"west" : AREA"g10",
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write(@DIRE
草丛里有个小平台，上头刻著：

		└
	      ↑  △
DIRE
	);
    return 1;
}

