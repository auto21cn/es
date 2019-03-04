// File: /d/eastland/easta/palace_se.c
// Generated by Roommaker Sat Nov 25 17:07:45 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("青鲤楼");
	ob->set_long( @LONG_DESCRIPTION
你现在来到了若岚宫东南角，青鲤楼前的广场，楼前用青石雕成的四十九只
鲤鱼宛如活鱼一般在你的眼前游动，映著大红色的若岚宫高大的宫墙，构成一幅
美妙的景象，广场南边和东边的胡同通往东大街和南大街。
LONG_DESCRIPTION
	);

	ob->set_outside( "easta" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/easta/east_salley", 
		"north" : "/d/eastland/easta/palace_e", 
		"south" : "/d/eastland/easta/south_ealley", 
		"west" : "/d/eastland/easta/palace_s" ]) );
	ob->set( "objects", ([ 
		"vistor2" : "/d/eastland/easta/monster/vistor", 
		"visitor1" : "/d/eastland/easta/monster/vistor" ]) );
	ob->reset();
}
