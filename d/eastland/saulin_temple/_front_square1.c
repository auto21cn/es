// File: /d/eastland/saulin_temple/front_square1.c
// Generated by Roommaker Wed Nov 22 23:31:30 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("广场");
	ob->set_long( @LONG_DESCRIPTION
这是一片用石板铺成的大广场，每个石板的中间都凹了下去，远远
望去好像水面上的波纹，十分的壮观。另外场边还摆\著许\多的兵器，看
来此处是是少林寺三千武僧练武的地方。此处的北边有一些殿堂，可惜
距离太远你看不到上面写的字，东边是一望无际的广场。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/front_square2", 
		"west" : "/d/eastland/saulin_temple/front_square3", 
		"north" : "/d/eastland/saulin_temple/front_square4" ]) );
	ob->set( "objects", ([ 
		"monk2" : "/d/eastland/saulin_temple/monster/bonze2" ]) );
	ob->reset();
}
