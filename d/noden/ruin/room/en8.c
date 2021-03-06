// entrance 8

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("地下水道");
    set_long(@C_LONG
这里是一个似乎已经废弃很久的输水道，空气中飘浮著一股令人不适的味
道。但是奇怪的是，这麽潮湿的地方连一只蟑螂都没有。你的面前有一条湍急
的小溪，北边的墙上画著一堆奇怪的符号，上面还有根扳杆 (lever)。
C_LONG
    );
    set("item_desc", ([
        "lever" : "这根扳杆不知道是什麽开关，你或许可以拉 (pull) 它。\n",
        "wall" : "这墙上画著一堆奇怪的符号，或许是某种文字也说不定。\n"
        ]) );
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_swim", "swim");
    add_action("to_search", "search");
}

int to_pull(string str)
{
    object p;
    p = this_player();

    if (str == "lever")
    {
	tell_object(p, "你拉了一下扳杆，但是它马上又弹回原来的位置，似乎什麽事情都没有发生 ....\n");
	p->delete_temp("lilia_0");
	tell_object(p, "咦? 地板什麽时候不见了? ... 哇～～～\n");
	tell_room(environment(p), "你听见一声惨叫，但是你左看右看，都看不到有什麽事发生 ....\n", ({p}));
	p->set_explore("noden#44");

	p->move(AREA"rose0");
	return 1;
    }
    else
	return notify_fail("你想拉什麽?\n");
}

int to_swim()
{
    object p;
    p = this_player();

    tell_object(p, "你正准备下水时，忽然脚下一个踩空 ... 哇～～～\n");
    switch (p->query_temp("lilia_0"))
    {
	case 6:
	    p->move(AREA"en6");
	    break;
	default:
	    p->move(AREA"en1");
	    break;
    }
    return 1;
}

int to_search()
{
    write("除了流向南方的水道外，什麽东西都没有。\n");
    return 1;
}

