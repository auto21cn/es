// File: /d/eastland/easta/west_nalley.c
// Generated by Roommaker Sat Nov 25 17:04:14 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("西大街");
	ob->set_long( @LONG_DESCRIPTION
你现在正位於若岚城的西大街上，整齐的街道上铺著青石砖，若岚城的街道
素有整洁美观的好评，你最好别任意制造脏乱，以免受人耻笑。
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/palace_nw", 
		"west" : "/d/eastland/easta/west_nlane" ]) );
	ob->reset();
}
