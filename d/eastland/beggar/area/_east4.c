// File: /d/eastland/beggar/area/east4.c
// Generated by Roommaker Thu Mar 21 18:08:26 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("村路");
	ob->set_long( @LONG_DESCRIPTION
你现在正走在一条由碎石子铺成的村 路上。村路向东、西方向延伸。村路不
很大,约可容纳一匹马行驶的宽度。在路旁长著一些奇形怪状的植物 ,那上面更开
著许多不知名的小花,小花闻起来有点淡淡的香味, 那味道说不出的使得你心旷神
怡。鸟语蛙呜, 顿时你烦恼尽失,站在这里真是有如仙境。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/east5.c", 
		"west" : "/d/eastland/beggar/area/east3.c" ]) );
	ob->reset();
}
