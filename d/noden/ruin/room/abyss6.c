// abyss6.c

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
	"bloodstrain" : "一片暗红的血迹，旁边还有个烛台 (standard)。\n",
	"standard" : "烛台里有根锥 (bodkin)，上头似乎有血迹。\n",
	"bodkin" : "这根椎如果戳 (prod) 在肉里，肯定会很痛。\n"
	]) );

    set("exits", ([
	"northwest" : AREA"abyss3",
	"northeast" : AREA"abyss4",
	"north" : AREA"abyss5",
	"southwest" : AREA"abyss1",
	"southeast" : AREA"abyss2",
	"south" : AREA"abyss0"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_prod", "prod");
}

int to_search()
{
    write("你找了又找，发现地上画著一个魔法阵，上面似乎有些血迹 (bloodstrain)。\n");
    return 1;
}

int to_prod()
{
    object p;
    p = this_player();

    p->receive_damage(5);
    tell_object(p, "你用尖锥戳了自己的手指一下 .... 好痛！流血了！ ....\n");
    tell_object(p, "你赶快把手指放到嘴里吸吮，但还是有滴血滴到了地上 ....\n");

    if (p->query_temp("lilia_abyss") == 6)
    {
	p->set_temp("block_command", 1);
	tell_object(p, "地上的魔法阵突然发出光芒，强大的魔力冲击著你每一根神经！\n");
    	call_out("activate", 15, p);
    }

    return 1;
}

int activate(object p)
{
    p->delete_temp("block_command");
    p->delete_temp("lilia_abyss");
    tell_object(p, "当你回过神来时，你发现眼前的景物已经变了...\n");
    p->move(AREA"abyss7");
    return 1;
}
