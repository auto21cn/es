#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小径");
	set_long(@Long
这里是工匠小径, 东边不远处就是城镇的东门了, 远远的可以望见门
外的广阔的原野。由小径往西可以到达镇上的中心广场, 那里有著附近最
大的市集。
Long
);
	set("exits", ([
		"east"		: HERE"east_gate",
		"west"		: HERE"tinker_way2",
		]));
}
