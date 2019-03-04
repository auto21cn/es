#include "nodania.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create();
	set_short( "王记商行" );
	set_long(@CLONG
你现在正站在一间充满东方风味的的商店中，这家店据说是当年
那位第一个踏上诺顿王国土地的东方人开的，店主人王富就是他的後
代。这家店现在已经是诺达尼亚城中牌子最老，信誉卓著的老字号了
，你在这里绝对不必担心被骗或买到次级品。
CLONG
	);
	set( "light", 1);
	set( "exits", ([
		"east" : NODANIA"nodania_r1"
	]) );
	set( "objects", ([ "trashcan": "/obj/trashcan" ]) );
	storeroom()->set( "objects", ([
		"bag#1" : "/obj/bag" ]) );
	replace_program(SHOP);
}
