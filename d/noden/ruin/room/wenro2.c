// wenro2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("峡谷的底部");
    set_long(@C_LONG
你来到了一个峡谷的底部，横在你面前的是一条清彻的河流，映著两岸高
耸峭壁的倒影，你不由得由心中赞叹起这美丽的造物主杰作。你身後的岩壁上
挂满了慵懒地垂著的藤蔓，藤蔓的後面似乎有个小洞。
C_LONG
    );
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
	this_player()->move(AREA"wenro3");
    }

    return 1;
}
