// wenro3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("峡谷的底部");
    set_long(@C_LONG
你来到了一个峡谷的底部，你的身後耸立著一片高高的山壁，上头的岩石
发出闪闪光芒，你不由得由心中赞叹起这美丽的造物主杰作。你後方的岩壁上
挂著些慵懒地垂著的藤蔓，藤蔓的後面似乎有个小洞。
C_LONG
    );
    set("exits", (["north" : AREA"wenro4"]));
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string s)
{
    if (!s || s != "hole")
	return notify_fail("你想进入哪里?\n");
    else
    {
	write("你穿过岩壁後的小洞，来到一个新的地方 ...\n");
	this_player()->move(AREA"wenro2");
    }

    return 1;
}
