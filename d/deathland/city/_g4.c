// File: /d/deathland/city/g4.c
// Generated by Roommaker Sat Nov 11 15:19:20 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("矮人墓场");
	ob->set_long( @LONG_DESCRIPTION
这里是矮人国度的墓场,墓场里埋藏著一些英勇战死的士兵的骨骸.每一座墓碑
的底下都有一个英勇的灵魂安息著.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/deathland/city/g6", 
		"north" : "/d/deathland/city/g3" ]) );
	ob->reset();
}
