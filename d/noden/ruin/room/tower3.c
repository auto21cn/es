// tower3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔术师塔．第一层");
    set_long(@C_LONG
这里是魔术师塔的第一层，地板上画满了密密麻麻的奇特咒文，似乎是用
来禁制某种可怕的生物用的。空气中充满了腐尸的气味，你的直觉告诉你如果
不快点设法离开这个地方，恐怕不久之後你也会变成一具尸体了。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"tower2",
	"east" : AREA"tower2",
	"south" : AREA"tower2",
	"west" : AREA"tower2"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string arg)
{
    write("你发现地上有块砖头似乎是某种秘门的按钮 (button)。\n");
    return 1;
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "这团迷雾慢慢地散去 .... 你发现四周的景物已经变了 ....\n");
    p->move(AREA"tower4");
    return 1;
}

int to_push(string arg)
{
    if (arg == "button")
    {
	write("一道黑雾迅速地笼罩在你的四周 ...\n");
        this_player()->set_temp("block_command", 1);
        call_out("recover", 15, this_player());
	return 1;
    }
    else
	return notify_fail("你想按什麽?\n");
}

