// File: /d/deathland/city/g8.c
// Generated by Roommaker Sat Nov 11 15:23:06 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("英雄墓场");
	ob->set_long( @LONG_DESCRIPTION
这里是矮人英雄的墓场,墓场里埋藏著一位有著伟大探险精神的人.这一座墓碑的碑铭
上写著: 开路的先锋.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/city/g7", 
		"north" : "/d/deathland/city/g9" ]) );
	ob->set( "search_desc", ([ 
		"here" : "@@search_here" ]) );
	ob->reset();
}
