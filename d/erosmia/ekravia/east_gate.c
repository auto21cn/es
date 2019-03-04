#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the east gate", "东门");
	set_long(@Long
你看到一道低矮的围墙, 与一道拱门。一条不宽不窄的道路由拱门下
穿过, 往东伸入广阔的田野中。围墙西边是一个幽雅的城镇, 那正是吟游
诗人们常常歌咏的美丽故乡「爱卡拉维亚」。
Long
);
	set("exits", ([
		"east"		: "/d/erosmia/11,10.erosmia",
		"west"		: HERE"tinker_way1",
		]));
}
