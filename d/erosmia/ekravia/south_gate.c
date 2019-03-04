#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the south gate", "南门");
	set_long(@Long
Long
,@CLong
你正站在一个美丽城镇的入口处。在古朴的土墙背後, 你隐隐约约地
望见不远处一栋栋砖红色的洋房。道路穿过大门延伸进去, 但已不再是田
野间的泥土小路, 而是一尘不染的石板大道。
CLong
);
	set("exits", ([
		"south"		: "/d/erosmia/10,11.erosmia",
		"north"		: HERE"maple_street1",
		]));
}
