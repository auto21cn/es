#include "ekravia.h"
inherit SHOP;

void	create()
{
	::create();
	set_light(1);
	set_short("shop","商店");
	set_long(@Long
这里是专门卖出与收购各种旅行冒险装备的杂货店, 你可以在这里找
到有名的冒险者们所留下来的装备。许\多传说中的名剑名铠都曾在这家商
店出现过, 更有不少的传奇故事是从这家商店开始的。
Long
);
	set("exits", ([
		"east"		: HERE"maple_street4",
	]));
	set("objects", ([
		"trashcan"	: "/obj/trashcan",
	]) );
	reset();		                                                                        
}
