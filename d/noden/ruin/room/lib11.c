// lib11.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．世界厅");
    set_long(@C_LONG
这是一个挂著「世界厅」牌匾的有趣房间，因为房间的地板上画了一张图，
上面有著注解：「帝国总览图」。「大概是因为这张地图才称做世界厅吧！」你
不由得打从心里这样想著。
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib12",
	"west" : AREA"lib10",
	"north" : AREA"lib13",
	"south" : AREA"lib14",
	"up" : AREA"lib15"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s != "map")
	return notify_fail("你想找什麽? 这里这麽大可能要找到明年哟 ...\n");

    if (p->query(QUESTNAME) >= 7)
    {
	tell_object(p, "当你凝神注视著这个地图时，你感到一阵晕眩 ...\n");
	p->move(AREA"p0");
    }
    else
	tell_object(p, "这是一张很美丽的地图，上面有山有水有鸟有鱼 ...\n");

    return 1;
}
