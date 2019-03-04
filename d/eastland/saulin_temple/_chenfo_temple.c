// File: /d/eastland/saulin_temple/chenfo_temple.c
// Generated by Roommaker Wed Nov 22 23:28:47 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("千佛殿");
	ob->set_long( @LONG_DESCRIPTION
你现在进入了千佛殿（又名毗卢殿），看见前方是一座毗卢佛，有六丈高，
神情庄严。前面的供桌上有水果，还很新鲜，可惜旁边有僧人在看，不然就可
以偷拿一两个来吃。东，北，西三面墙上是吴道子所绘「五百罗汉朝毗卢图」
，气势非凡，人物刻划细致，不愧\为一代大师之作。门外是一条走廊。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/hallway6" ]) );
	ob->set( "objects", ([ 
		"monka" : "/d/eastland/saulin_temple/monster/little_monk", 
		"monkb" : "/d/eastland/saulin_temple/monster/hwa_son" ]) );
	ob->reset();
}
