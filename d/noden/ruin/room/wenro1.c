// wenro1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("峡谷的底部");
    set_long(@C_LONG
你来到了一个峡谷的底部，横在你面前的是一条清彻的河流，映著两岸高
耸峭壁的倒影，你不由得由心中赞叹起这美丽的造物主杰作。你身後的岩壁上
挂满了慵懒地垂著的藤蔓，藤蔓的後面似乎藏著有字。
C_LONG
    );
    set("exits", (["west" : AREA"wenro2"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_swim", "swim");
}

int to_search()
{
    write("岩壁上写著：响应大家来飞行运动，请勿在此游泳。\n");
    return 1;
}

int to_swim()
{
    write("你不费吹灰之力地游到了对岸 ....\n");
    this_player()->move(AREA"wenro0");
    return 1;
}

