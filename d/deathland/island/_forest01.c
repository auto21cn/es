// File: /d/deathland/island/forest01.c
// Generated by Roommaker Thu Nov 23 19:54:48 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("灰暗之岛的森林");
	ob->set_long( @LONG_DESCRIPTION
一个黑漆漆的森林, 这森林似乎充满著荆棘与矮灌木, 地上都是腐烂的树叶, 是
个令人很想逃离的地方. 这里的地势似乎越往东南就越高, 你仍能见到河水急速的流
动, 但是往东南方一直走的话, 你将远离河流而进入森林的深处. 
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"northwest" : "/d/deathland/island/i01", 
		"southeast" : "/d/deathland/island/forest02" ]) );
	ob->reset();
}
