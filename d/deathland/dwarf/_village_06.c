// File: /d/deathland/dwarf/village_06.c
// Generated by Roommaker Thu Nov 23 19:34:16 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("通往矮人的村落的小路");
	ob->set_long( @LONG_DESCRIPTION
你已经到了矮人村落的入口,一个板子立在通道的旁边,上面写著:
----非请勿入---
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/dwarf/village_07", 
		"south" : "/d/deathland/dwarf/village_05" ]) );
	ob->reset();
}
