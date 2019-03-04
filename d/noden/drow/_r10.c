// File: /d/noden/drow/r10.c
// Generated by Roommaker Mon Nov 27 14:20:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("贵族宅院");
	ob->set_long( @LONG_DESCRIPTION
这里是一个美丽的宅院，低矮的围墙上，依然雕刻著蜘蛛的图纹，
小小的庭院种植一些奇奇怪怪的蔬菜，一间石房就在庭院的中央，也许
是黑暗精灵天性的节俭吧，这看似朴实的庭院，就是他们贵族平日居住
的地方，你不禁想想，黑暗精灵的节俭可能跟他们的生活环境有关吧。
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"west" : "/d/noden/drow/r09" ]) );
	ob->set( "objects", ([ 
		"Pan" : "/d/noden/drow/mob/pan" ]) );
	ob->reset();
}
