// File: /d/noden/recamp/camp8.c
// Generated by Roommaker Sat Nov 25 14:29:10 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("地道");
	ob->set_long( @LONG_DESCRIPTION
这条神秘的地道，壁上镶嵌著耀眼明亮的珠子，照亮整个通道，壁上还绘著
一只瘦小的恐龙怪物，正大肆破坏诺顿王国东北村落，令人不禁胆跳心惊。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/recamp/camp5", 
		"down" : "/d/noden/recamp/camp_pool" ]) );
	ob->set( "objects", ([ 
		"rat2" : "/d/noden/farwind/monster/grey_rat", 
		"rat1" : "/d/noden/farwind/monster/grey_rat" ]) );
	ob->reset();
}
