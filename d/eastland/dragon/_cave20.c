// File: /d/eastland/dragon/cave20.c
// Generated by Roommaker Sat Nov 25 14:04:05 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("龙穴");
	ob->set_long( @LONG_DESCRIPTION
你发现此处是一个火山熔洞，四周都是奇怪的火红色岩石，并且有时有一些奇怪的岩
石结晶，当其被火光映照之时，会反射出绚丽的光线，加上原有的火红构成一副优美的景
色，令你几乎忘了身在何处。
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/dragon/cave4", 
		"west" : "/d/eastland/dragon/cave6" ]) );
	ob->reset();
}
