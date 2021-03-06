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
你走在一条大街上, 两旁各种著一排枫树。几片红色的枫叶不时在你
的面前飘落, 别有一番情调。大街上并没有多少人迹, 四周大多也是低矮
的平房, 使这里显得格外地恬静。
    西边有一条小路, 仔细倾听, 似乎有些鸡、鸭鸣叫的声音由那边传来
CLong
);
	set("exits", ([
		"south"		: HERE"south_gate",
		"north"		: HERE"maple_street2",
		"west"		: HERE"small_road1"
		]));
}
