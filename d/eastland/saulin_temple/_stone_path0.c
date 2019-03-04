// File: /d/eastland/saulin_temple/stone_path0.c
// Generated by Roommaker Wed Nov 22 22:59:30 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("石阶小径");
	ob->set_long( @LONG_DESCRIPTION
你走在少林寺内千廊百院间的通道上，磨损得圆润光华的石阶无言的对你
夸耀少林寺的悠久历史。遥望寺外蓊郁松林，寺内黄瓦朱墙，寺僧来去、游客
相接，你不禁有出世之想。往南北方望去各式一条小径，东边是客房，西边则
是禅房。
LONG_DESCRIPTION
	);

	ob->set_outside( "saulin_temple" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/guess_house1", 
		"west" : "/d/eastland/saulin_temple/monk_room1", 
		"south" : "/d/eastland/saulin_temple/stone_path1", 
		"north" : "/d/eastland/saulin_temple/grass5" ]) );
	ob->reset();
}
