// File: /d/eastland/easta/south_walley.c
// Generated by Roommaker Sat Nov 25 17:05:42 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("南大街西胡同");
	ob->set_long( @LONG_DESCRIPTION
你现在正位於若岚城的南大街上，整齐的街道上铺著青石砖，若岚城的街道
素有整洁美观的好评，你最好别任意制造脏乱，以免受人耻笑。
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/easta/palace_sw", 
		"south" : "/d/eastland/easta/south_wlane" ]) );
	ob->reset();
}
