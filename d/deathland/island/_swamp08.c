// File: /d/deathland/island/swamp08.c
// Generated by Roommaker Thu Nov 23 19:46:45 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("灰暗之岛的沼泽");
	ob->set_long( @LONG_DESCRIPTION
一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你必须小心谨慎
你的每一步. 越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮住了. 这
地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经快深陷於沼泽里了.

LONG_DESCRIPTION
	);

	ob->set( "exit_invisble", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/deathland/island/swamp12", 
		"south" : "/d/deathland/island/swamp09", 
		"west" : "/d/deathland/island/swamp04" ]) );
	ob->reset();
}
