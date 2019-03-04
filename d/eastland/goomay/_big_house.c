// File: /d/eastland/goomay/big_house.c
// Generated by Roommaker Thu Nov 23 18:43:23 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("四不欺大院");
	ob->set_long( @LONG_DESCRIPTION
这是著名的清官－文若水告老还乡後所建的大宅，它是一栋占地极广的
四合院，因为悬在门口的皇上御笔－「四不欺」而得名，原来的名字反而被
淡忘了。文若水虽然已经去世，但是他的子孙仍然极为显赫，所以四不欺大
院在本镇是权势与富贵的表徵，东西方各有一个门，南方是正厅大门，不过
这些门都紧闭著。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"north" : "/d/eastland/goomay/row21" ]) );
	ob->set( "objects", ([ 
		"guard2" : "/d/eastland/goomay/monster/bodyguard", 
		"guard1" : "/d/eastland/goomay/monster/bodyguard", 
		"dog" : "/d/eastland/goomay/monster/watchdog" ]) );
	ob->reset();
}
