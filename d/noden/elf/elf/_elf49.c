// File: /d/noden/elf/elf/elf49.c
// Generated by Roommaker Mon Dec  4 21:55:06 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草原");
	ob->set_long( @LONG_DESCRIPTION
这里是一望无际的大草原，有无数的动物生长在这里，有几株矮灌木孤零
零的立著，这里的植物都是非常适合小动物生长，有可以躲避的半人高芒草及
荆棘丛，有柔细可口的牧草，真是小动物的天堂。
LONG_DESCRIPTION
	);

	ob->set_outside( "elfhamlat" );
	ob->set( "exits", ([ 
		"northwest" : "/d/noden/elf/elf/elf48.c", 
		"south" : "/d/noden/elf/elf/elf51" ]) );
	ob->reset();
}
