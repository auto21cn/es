// File: /d/eastland/saulin_temple/lohan_temple.c
// Generated by Roommaker Wed Nov 22 23:38:20 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("罗汉堂");
	ob->set_long( @LONG_DESCRIPTION
一踏进罗汉堂你的眼光立刻被两旁供奉的十八罗汉所吸引，降龙伏虎
迦叶阿难等等神态姿势各异其趣的罗汉塑像分立两旁，它们背後的墙上各
自绘著每一名罗汉苦修成道的壁画。同时这里也是寺中武艺有成的武僧互
相切磋功\力的地方，现在正有不少武僧在切磋讨论，拳来掌往刀光剑影十
分热闹。门外是一条走廊。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/saulin_temple/hallway8" ]) );
	ob->reset();
}
