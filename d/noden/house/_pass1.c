// File: /d/noden/house/pass1.c
// Generated by Roommaker Mon Dec  4 20:59:19 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("阴暗走廊");
	ob->set_long( @LONG_DESCRIPTION
你现在走在一条阴暗的走廊上，脚下踩著的木板发出「吱嘎」的声音，似乎只要
稍一用力就会陷下去，两边的墙上挂著一些发黄的人物肖像画(painting)，你看到北
边走廊的尽头好像有灯光，不....也许是错觉吧，这种阴森森的环境特别容易使人产
生不愉快的错觉。
LONG_DESCRIPTION
	);

	ob->set( "c_item_desc", ([ 
		"painting" : @LONG_TEXT
东边的肖像画是一位穿著华丽的贵妇人，当你注视这幅画的时候，好像听到背
後一声冷笑，你回过头来，除了西边那幅威武骑士的肖像画，什麽也没有看见。
LONG_TEXT
 ]) );
	ob->set( "exits", ([ 
		"south" : "/d/noden/house/hall", 
		"north" : "/d/noden/house/pass2" ]) );
	ob->set( "objects", ([ 
		"wisp#1" : "/d/noden/house/monster/wisp", 
		"wisp#2" : "/d/noden/house/monster/wisp" ]) );
	ob->reset();
}
