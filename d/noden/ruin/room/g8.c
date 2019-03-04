// g8.c

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
	"south" : AREA"g2"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_sketch", "sketch");
}

int to_search()
{
    write("草丛里有一颗闪闪发亮的绿色水晶，水晶的上头有奇怪的图案。\n");
    return 1;
}


int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 5)
    {
        return notify_fail("你已经画过一次了，就省省力气吧。\n");
    }

    p->set(QUESTNAME, 5);
    tell_object(p, "你小心翼翼地把海地亚之印描绘在魔法字典的笔记栏里。\n");
    return 1;
}

