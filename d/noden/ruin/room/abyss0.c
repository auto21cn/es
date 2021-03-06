// abyss0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("深渊");
    set_long(@C_LONG
你现在处於一个深渊的底部，四周围绕著一片灰蒙蒙的雾气。虽然是在浓
雾之中，但是你隐约觉得有许多眼睛正在窥伺著你，彷佛像地狱中探头出来的
恶灵一般地鬼鬼祟祟。在这片黑暗之中，找到光明似乎正是你的当务之急。
C_LONG
    );
    set("item_desc", ([
	"candle" : "一根惨白的白色蜡烛，点亮它或许可以得到光明。\n"
	]) );
    set("exits", ([
	"northwest" : AREA"abyss1",
	"northeast" : AREA"abyss2",
	"north" : AREA"abyss6"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_light", "light");
}

int to_search()
{
    write("你找了又找，发现地上插著根蜡烛 (candle)。\n");
    return 1;
}

int to_light(string s)
{
    object p;
    int count;

    if (s != "candle")
	return notify_fail("你想点亮什麽？\n");

    p = this_player();
    tell_object(p, "你点亮了蜡烛 ... 但是它却自动熄灭了 ...\n");

    if (p->query_temp("lilia_abyss"))
    	count = p->query_temp("lilia_abyss");
    else
	count = 0;

    if (count < 1)
        count++;

    p->set_temp("lilia_abyss", count);
    return 1;
} 
