// File: /d/noden/elf/elf/elf28.c
// Generated by Roommaker Mon Dec  4 21:49:34 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("草原");
	ob->set_long( @LONG_DESCRIPTION
这里是大草原(plain)的尽头，你的眼前有一条小河流过，河水清澈的
连河底的小石子都看的清清楚楚，这的确是一个群居的好地方，无数野牛
脚印散落地面，遍地的青草有被撕咬过的痕迹，而草丛中时而传来阵阵牛
鸣声，你想这附近大概有野牛的巢穴。
LONG_DESCRIPTION
	);

	ob->set_outside( "elf_hamlet" );
	ob->set( "exits", ([ 
		"north" : "/d/noden/elf/elf/elf26" ]) );
	ob->set( "item_desc", ([ 
		"plain" : @LONG_TEXT
这里长满著青翠的小草，几丛灌木孤独地耸立著，虽然此处看起来
十分平静，但是据说附近常有野兽出没，故而此处是精灵们的狩
猎场。
LONG_TEXT
 ]) );
	ob->set( "objects", ([ 
		"buffalo2" : "/d/noden/elf/monster/buffalo", 
		"buffalo1" : "/d/noden/elf/monster/buffalo", 
		"buffalo3" : "/d/noden/elf/monster/buffalo" ]) );
	ob->reset();
}
