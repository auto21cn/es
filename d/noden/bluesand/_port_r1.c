// File: /d/noden/bluesand/port_r1.c
// Generated by Roommaker Mon Dec  4 22:09:51 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("港湾路");
	ob->set_long( @LONG_DESCRIPTION
你现在走在蓝沙港主要的街道，港湾路上。在你的北边是一片白中带
著淡蓝色细点的沙滩，码头在你的东方不远处，南边是蓝沙港著名的水手
酒吧，顺著港湾路向西可以离开蓝沙港。
LONG_DESCRIPTION
	);

	ob->set_outside( "bluesand" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/bluesand/port_r2.c", 
		"south" : "/d/noden/bluesand/pub.c", 
		"west" : "/d/noden/bluesand/port_r0.c", 
		"north" : "/d/noden/bluesand/beach" ]) );
	ob->reset();
}
