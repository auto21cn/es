// lib6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．长廊");
    set_long(@C_LONG
你现在身处於一条长长的走廊上，大理石铺成的走道向西方延伸。东边墙  
壁上有个小铜环，似乎是某种开关 (switch) 。长廊的墙壁不知是用什麽东西
所建造的，闪耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib5",
	]) );
    set("item_desc", ([
	"wall" : "墙上画著一串好像是烤肉的东西 .... 嗯 :D~~~~\n",
	"switch" : "这个铜环好像可以拉 (pull) 的样子 ....\n"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_search", "search");
}

int to_pull(string s)
{
    object p;
    p = this_player();

    if (s == "switch")
    {
	tell_object(p, @NOTHING
你小心地拉动铜环，但是似乎什麽事情都没有发生 .....
..............

地板好像又不见了的样子 .....
..............

哇～～～

NOTHING
	);
	p->move(AREA"lib7");
        tell_room(environment(p), "你听见一声惨叫，但是你左看右看，都看不到有什麽事发生 ....\n", ({p}));
        return 1;
    }
    else
	return notify_fail("你想拉什麽?\n");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "south")
    {
	tell_object(p, @OK
当你盯著南边墙上画的烤肉串流口水的时候，忽然发现墙角有个按钮，於是
你顺手一按 .... 

你的眼前突然强光一闪，当你恢复视觉时，你发现四周的景物已经变了 ....

OK
	);
	p->move(AREA"lib8");
	return 1;
    }
    else return notify_fail("你想找什麽? 这里有什麽有趣的东西吗?\n");
}

