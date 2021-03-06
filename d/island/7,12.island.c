// File: 7,12.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("岩石平台");
	set_long( @LONG_DESCRIPTION
这岩石平台在沼泽中十分显明，平台上十分平整，显然是蜥蜴人用心
修整的结果，平常这台上是没有多少人的，只有进出的人经过，但是一发
生战争，蜥蜴人便在此集合兵马，那是很壮观的场面；这平台中央便是洞
穴入口了，里头黑黝黝的，有点吓人，拿出勇气，下去看看吧！不过洞口
上有一个告示牌(sign)，也许你该看一看。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"7,11.island", 
		"down"  : "/d/island/hole/hole00"
		]) );
	set( "original", ISLAND"7,12" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 12 );
        set( "no_monster" , 1 );
        set( "item_desc",([ "sign":"由於失去神力的庇佑，洞内有很大的改变喔！\n" ]));
	reset();
#include <replace_room.h>
}

