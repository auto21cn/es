// File: /d/deathland/troll/cave_09.c
// Generated by Roommaker Thu Nov 23 20:58:11 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("充满了血迹和骨骸的洞");
	ob->set_long( @LONG_DESCRIPTION
整个洞穴到处都是山顶巨人的脚印,明显地你已经进入了山顶巨人的领域
了.血迹及骨骸到处可见,山顶巨人的嗜血和好杀由此可知.对於一个没有勇气
的人来讲,沿著原路退回将是活命的唯一机会. 你慢慢地已经进入巨人洞穴的
深处了,运气对你来讲是越来越重要. 
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/troll/cave_08", 
		"west" : "/d/deathland/troll/cave_10" ]) );
	ob->reset();
}
