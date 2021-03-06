// wenro5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("祭坛");
    set_long(@C_LONG
这里有个被树林环绕著的祭坛 (altar)，祭坛上有个和人身一样大小的美
丽雕像 (statue) 。虽然景致非常地优美，但是你总觉得空气中弥漫著一股难
以形容的忧伤气氛，与前头的欢乐气息迥然不同。这气氛难道是那个年轻人造
成的吗？
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
	"altar" : "一个花岗石祭坛，也许可以供奉 (dedicate) 些什麽。\n",
	"statue" : "一座刻的栩栩如生的美女雕像。\n"
	]));
    reset();
}

void init()
{
    add_action("do_dedicate", "dedicate");
    add_action("do_kiss", "kiss");
}

int do_dedicate()
{
    object f; 
    if (f = present("casablanca", this_player()))
    {
	write("你把香水百合供奉在祭坛上。\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
	return notify_fail("你身上没有什麽可供奉的东西。\n");
}

int do_kiss(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
	    write("你发现卡谬正恶狠狠地瞪著你，还是别亲的好。\n");
	    return 1;
	}
        else    
	{
	    write("你轻轻地亲吻了一下神像的脸，突然间感到一阵天旋地转 ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
	return notify_fail("你想亲什麽?\n");
}

