#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short( "西门" );
	set_long(@Long
这里是爱卡拉维亚的西门, 道路往西进入山区, 最後通往山中的宝石
矿坑。回头往东则是平静的小镇街道。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way5",
		"west"		: "/d/erosmia/9,10.erosmia",
		]));
}
