// File: /d/noden/12,13.noden.c
// Generated by Roommaker Tue Nov 21 00:24:34 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("沼泽");
	ob->set_long( @LONG_DESCRIPTION
你现在来到一处海边的沼地，由於海水的冲刷，这里的臭味比起沼泽
中其他地方减轻了不少，你注意到海岸边有一块突起的岩石(rock)，孤独
地立在乌黑的沼泥和海边的细沙之中。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "c_item_desc", ([ 
		"rock" : "这块岩石下隐藏著一个小洞，里面似乎有一些小生物在活动。\n" ]) );
	ob->set( "exits", ([ 
		"east" : "d/noden/13,13.noden", 
		"north" : "d/noden/12,12.noden", 
		"west" : "d/noden/11,13.noden" ]) );
	ob->set( "objects", ([ 
		"crab" : "/d/noden/monster/crab" ]) );
	ob->set( "original", "d/noden/12,13" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 12 );
	ob->set( "y_coordinate", 13 );
	ob->reset();
}
