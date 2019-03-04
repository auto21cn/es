#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小径");
	set_long(@Long
工匠小径沿著东西方向延伸。西边不远处就是镇上的中心广场, 南边
有一家小药屋。从这里往东一段距离可以看到东门, 从东门出去则是一片
广阔的原野。
Long
);
	set("exits", ([
		"south"		: HERE"potion_shop",
		"east"		: HERE"tinker_way2",
		"west"		: HERE"square",
		]));
}
