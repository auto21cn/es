#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("中心广场");
	set_long(@Long
这里是整个爱卡拉维雅镇的心脏地带, 东西向的工匠小径与往南延伸
的枫树大街在此交会, 形成一个大广场。许\多的小贩旅行商人们在这里交
易著工艺品与食物。几个旅行艺人或是魔术师在此卖艺, 不时引出阵阵的
欢笑声。
    广场的北边是镇长的公馆, 也是整个镇上最豪华的的一栋建筑。
Long
);
	set("exits", ([
		"south"		: HERE"maple_street4",
		"east"		: HERE"tinker_way3",
		"west"		: HERE"tinker_way4",
		]));
	set( "objects", ([
		"magician"	: MOB"magician",
		"vendor"	: "/obj/vendor",
		]) );
	reset();
}
