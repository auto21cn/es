// /d/ocean/ocean.c

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "空房间");
	set_long(
		"This is a simple room created by roommaker.\n",
		"这是一个用房间编辑器造出来的空房间。\n"
	);
}
