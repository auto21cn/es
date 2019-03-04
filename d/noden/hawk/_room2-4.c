// File: /d/noden/hawk/room2-4.c
// Generated by Roommaker Mon Sep 30 14:34:09 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("碧玉森林");
	ob->set_long( @LONG_DESCRIPTION
这里是鸟人族人最引以自豪的碧玉森林，所有的树干都泛著淡绿色的光
茫，又彷佛可以直视入树干的内部。这种树即使是如你一般见闻广博的旅行
家也是前所未见的。树林里更弥漫著一股淡淡的香味，更是让你留连忘返。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/noden/hawk/room2-2", 
		"northeast" : "/d/noden/hawk/room2-5" ]) );
	ob->set( "objects", ([ 
		"tailor" : "/d/noden/hawk/monster/saw" ]) );
	ob->reset();
}
