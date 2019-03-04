// File: /d/eastland/goomay/coliseum1.c
// Generated by Roommaker Thu Nov 23 18:54:20 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("武斗大会会场");
	ob->set_long( @LONG_DESCRIPTION
这里是每一个习武者梦寐以求的成名地－天下第一武斗大会会场。在这片
宽阔的会场上，到处摆\著刀剑架子和箭垛把子，此刻正有许\多人在场上，或练
功\或决斗，拳脚声哀号声不时传来。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "PK_ZONE", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/coliseum2", 
		"west" : "/d/eastland/goomay/coliseum3", 
		"south" : "/d/eastland/goomay/coliseum4", 
		"north" : "/d/eastland/goomay/coliseum4" ]) );
	ob->set( "objects", ([ 
		"man1" : "/d/eastland/goomay/monster/din" ]) );
	ob->reset();
}
