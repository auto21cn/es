// min7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿内厅");
    set_long(@C_LONG
你现在在神殿的内厅里，凛冽的寒风依然吹个不停，你不由得紧了
紧身上的衣服。北方的墙壁上有个神龛 (niche)，里头飘浮著一个发光
的橙色水晶，水晶的上头似乎有些奇怪的图案。
C_LONG
    );
    set("exits", ([
	"south" : AREA"min6"
	]) );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
这是一个由大理石所雕制而成的神龛，神龛的前方有个小牌子，上面写
著：「迷途的羔羊啊! 对巴拉斯之印虔诚地祈祷吧! 」。
NICHE
	]) );
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_pray", "pray");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 2)
    {
        return notify_fail("你已经画过一次了，就省省力气吧。\n");
    }

    p->set(QUESTNAME, 2);
    tell_object(p, "你小心翼翼地把巴拉斯之印描绘在魔法字典的笔记栏里。\n");
    return 1;
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下来向水晶祈祷，祈祷些什麽好呢? ...\n");
    p->delete_temp("lilia_pass");
    p->move(AREA"rose4");
    return 1;
}
