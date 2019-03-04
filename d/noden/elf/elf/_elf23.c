// File: /d/noden/elf/elf/elf23.c
// Generated by Roommaker Mon Dec  4 21:46:21 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草原");
	ob->set_long( @LONG_DESCRIPTION
这里是一望无际的大草原(plain)，有无数的动物生长在这里，你的眼前
有一些草丛(bushes)肃立著。有一条小河从草原的南方缓缓的流过。
LONG_DESCRIPTION
	);

	ob->set_outside( "elfhamlat" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/elf/elf/elf22" ]) );
	ob->set( "item_desc", ([ 
		"plain" : @LONG_TEXT
这里长满著青翠的小草，几丛灌木孤独地耸立著，虽然此处看起来
十分平静，但是据说附近常有野兽出没，故而此处是精灵们的狩
猎场。
LONG_TEXT
, 
		"bushes" : "这些草丛长满荆棘你应该不能通过(pass)它\n" ]) );
	ob->set( "objects", ([ 
		"elephant2" : "/d/noden/elf/monster/elephant", 
		"elephant1" : "/d/noden/elf/monster/elephant" ]) );
	ob->reset();
}
