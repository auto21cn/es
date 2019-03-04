#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","枫树大街");
	set_long(@Long
Long
,@CLong
你走在繁华的大街上, 两旁开满了各式各样的商店。镇上唯一的冒险
者杂货店就开在大街西边的一栋大洋房中。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street3",
		"north"		: HERE"square",
		"west"		: HERE"shop"
		]));
}
