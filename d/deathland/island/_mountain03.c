// File: /d/deathland/island/mountain03.c
// Generated by Roommaker Thu Nov 23 19:52:27 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("灰暗之岛的祭坛");
	ob->set_long( @LONG_DESCRIPTION
这地方似乎是一个古代的祭坛, 在祭坛的正中央有著一个奇怪的阶梯通往地下深处,
一种神圣的力量从地底传出, 你能清楚地感受这力量的存在.
    西边有著一道很强劲的力场保卫这个神圣的地方. 究竟地底下是甚麽地方呢?     
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"down" : "/d/deathland/island/stair01", 
		"west" : "/d/deathland/island/mountain02" ]) );
	ob->reset();
}
