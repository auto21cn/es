// File: /d/noden/5,12.noden.c
// Generated by Roommaker Tue Nov 21 00:42:02 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("道路");
	ob->set_long( @LONG_DESCRIPTION
你现在正走在一条碎石铺成的道路上，道路向南、北方延伸。路旁的草
地上长著一些不知名的野花及野草。南边是魔法之都——摩亚达城。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/6,12.noden", 
		"west" : "d/noden/4,12.noden", 
		"north" : "d/noden/5,11.noden", 
		"south" : "d/noden/moyada/n_gate" ]) );
	ob->set( "original", "d/noden/5,12" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 5 );
	ob->set( "y_coordinate", 12 );
	ob->reset();
}
