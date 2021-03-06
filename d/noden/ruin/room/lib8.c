// lib8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大图书馆．秘室");
    set_long(@C_LONG
这是一个空空汤汤的房间，房间的中央飘浮著一颗闪亮的红水晶。你仔细
一瞧，水晶上还画著奇怪的图案。东边的墙上刻著一些碑文 (runes)，北边是
一个魔法力场，似乎可以通过的样子。
C_LONG
    );
    set("exits", (["north" : AREA"lib6"]));
    set("item_desc", ([
	"runes" : @RUNE
可敬的勇士：

    红水晶上的图案就是传说中的纳突尼之印，你可以把它描绘 (sketch) 下
来带在你的身上，就可以获得封印之门的认可，穿过封印之门到达被封印的地
方去。

    愿吾神女王荣光常伴左右。

					希达．尼普顿
RUNE
	]) );
    
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
}

int to_sketch()
{
    object p;
    p = this_player();
    
    if (p->query(QUESTNAME) >= 1)
    {
	return notify_fail("你已经画过一次了，就省省力气吧。\n");
    }

    p->set(QUESTNAME, 1);
    tell_object(p, "你小心翼翼地把纳突尼之印描绘在魔法字典的笔记栏里。\n");
    write("[你完成了 失落的封印 第一阶段的任务，获得 5000 点经验]\n");
    this_player()->finish_quest(QUESTNAME, 1);
    this_player()->gain_experience(5000);
    return 1;
}

