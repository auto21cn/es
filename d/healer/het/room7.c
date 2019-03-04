#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("花圃");
	set_long(@LONG
走到这里，让你眼前一亮。这里开满了各种花，放眼望去，一片花海。阵阵花香，
让你觉得彷佛身在仙境。红的、黄的、白的、蓝的、紫的甚至稀有的黑色的花，这里
都可以看到。水桶，小铲子，锄头等等工具四处散著，显然这里的花是有人细心照顾
的。
LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room1" 
	]));

	reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object o;

    write("你找了半天，除了花之外还是花 ....\n");
    o = new("/d/healer/plant/opium_poppy_plant");
    o->move(this_object());
    return 1;
}

