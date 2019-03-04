// File: /d/eastland/dragon/cave16.c
// Generated by Roommaker Sat Nov 25 14:03:15 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地下城");
	ob->set_long( @LONG_DESCRIPTION
此处是一个古老的地下城，此处的墙壁及地板都是以大理石铺设成的同时墙上正有几
只火把燃烧著，而天花板上则有许\多的奇怪的小孔，应该是此地下城的通风孔，由四周的
景物看来此地必定有千年以上的历史，但是景物依旧且空气清新，你不得不佩服当初设计
人的匠心与才气。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/dragon/cave11", 
		"west" : "/d/eastland/dragon/cave22" ]) );
	ob->reset();
}
