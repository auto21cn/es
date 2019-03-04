#include "forest.h"
inherit ROOM;

void create()
{
	::create();
	set_short("黑森林");
	set_long(@CLong
你走在阴森的黑森林中, 一股无法忽视的邪恶气息让你的神经异常地
紧绷。在这里到处都可能充满著危险, 注意你的四周! 小心不要成了黑暗
生物们的点心。
CLong
);
	set("exits",([
			"east"	: HERE"3n1w",
			"south"	: HERE"2n2w",
    ]));
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
    set("exit_suppress", ({ "south", }) );
	reset();

}
