// lib15.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．展览室");
    set_long(@C_LONG
这房间里空空汤汤，只有一张大石台，上头安置著一个闪闪发亮的水晶球。
石台的前方有个小牌子，上面写著：「传说中的神奇水晶球，可以指引勇者到试
炼的地方去。」
C_LONG
    );
    set("exits", (["down" : AREA"lib11"]));
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_touch", "touch");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "ball" || str == "crystal ball" || str == "水晶球")
    {
	if (p->query(QUESTNAME) >= 6)
	{
            tell_object(p, "水晶球呼应你身上封印的力量，发出一道光芒笼罩著你，你发现自己被传送到别的地方!\n");
            p->move_player(AREA"tower0", ({"%s被一道诡异的光芒传送走了!\n", "%s伴随著一道光芒出现在这里。\n"}), "" );
        }
	else
	    tell_object(p, "你摸了摸水晶球，但是似乎什麽事情都没有发生。\n");

	return 1;
    }
    else
        return notify_fail("你想摸什麽? 随便乱摸是不好的行为哦 ....\n");
}

