#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小径");
	set_long(@Long
你走在工匠小径上, 北边有一间造型奇特的魔法屋。里面不知在贩卖
著什麽奇怪的物品。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way1",
		"west"		: HERE"tinker_way3",
		"north"		: HERE"magic_shop",
		]));
}
