// File: /d/eastland/dragon/cave13.c
// Generated by Roommaker Sat Nov 25 14:02:39 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地下城出口");
	ob->set_long( @LONG_DESCRIPTION
此处是一个古老的地下城房间，此处的墙壁及地板都是以大理石铺设成的同时墙上正
有几只火把燃烧著，而天花板上则有许\多的奇怪的小孔，应该是此地下城的通风孔，由四
周的景物看来此地必定有千年以上的历史，但是景物依旧且空气清新，你不得不佩服当初
设计人的匠心与才气，你的前方似乎有一些不同於火把的光线透出。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/dragon/cave10", 
		"south" : "/d/eastland/dragon/cave18" ]) );
	ob->set( "objects", ([ 
		"soldier2" : "/d/eastland/dragon/monster/soldier", 
		"soldier1" : "/d/eastland/dragon/monster/soldier" ]) );
	ob->reset();
}
