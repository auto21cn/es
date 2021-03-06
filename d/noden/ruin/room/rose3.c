// rose3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("罗斯托丽城．城门");
    set_long(@C_LONG
你正站在一个悬崖的顶端，对岸是罗斯托丽城的城门。和前面断垣残壁的
景像截然不同，这个城门气派宏伟无比，不禁令人神往古魔族帝国的辉煌。不
过麻烦的是，要如何渡过这个悬崖到对岸呢？
C_LONG
    );
    set("exits", (["south" : AREA"rose2"]) );

    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_read", "read");
    add_action("do_jump", "jump");
    add_action("do_answer", "answer");
}

int do_search()
{
    tell_object(this_player(), "你发现脚下踩著一块石碑，上面写著一些文字。\n");
    return 1;
}

int do_read(string str)
{
    object p;
    p = this_player();

    if (str == "rune" || str == "runes")
    {
	if (p->query_temp("lilia_dic") == 1)
	    tell_object(p, "石碑上写著：「回答密语，女王荣光常伴」\n");
	else
	    return notify_fail("你看了半天，还是不知道上面写些什麽。\n");
    }
    else
	return notify_fail("你想读什麽?\n");
    return 1;
}

int do_jump(string str)
{
    object p;
    p = this_player();

    if (!str || str != "down")
	return notify_fail("你想干什麽? 想往下跳的话想清楚再跳哦 ...\n");
    else
    {
	tell_object(p, "你奋力向前一跃 ....\n\n");
	tell_room(environment(p), sprintf("%s很冲动地向悬崖底跳了下去 ....\n", p->query("c_name")), ({p}));
	tell_object(p, "你被水流冲到一个新的地方 ....\n\n");
	p->move("/d/noden/11,6.noden");
    }

    return 1;
}

int do_answer(string str)
{
    object p;
    p = this_player();
	
    if (str == "芝麻开门" || str == "open sesame")
    {
	if (p->query_temp("lilia_dic") != 1)
	    return notify_fail("你突然想起你还没拿字典，进城去也没用，於是就硬生生地把说到一半的话吞了回去。\n");
	p->set_explore("noden#47");
	tell_object(p, "忽然一阵白色的光芒笼罩在你四周，当光散去时，你发现四周的景物已经变了!\n");
	p->move_player(AREA"rose4", ({"%s被一道白光传送走了!\n", "%s伴随著一道光芒出现在这里。\n"}), "");
    }
    else
	return notify_fail("女王的声音从四面八方传来：「不懂密码就不要来吵我 ok?」\n");
    return 1;
}

