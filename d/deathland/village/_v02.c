// File: /d/deathland/village/v02.c
// Generated by Roommaker Thu Nov 23 21:03:57 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("矮人村落的入口");
	ob->set_long( @LONG_DESCRIPTION
往北边就是矮人的村庄.一些矮人们的小孩与老人居住在那里.由於迷宫的保护,
这里已经多年没有战争了.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/village/v01", 
		"north" : "/d/deathland/village/v03" ]) );
	ob->set( "objects", ([ 
		"guard" : "/d/deathland/monster/guard01" ]) );
	ob->reset();
}
