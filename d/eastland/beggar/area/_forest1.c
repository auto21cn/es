// File: /d/eastland/beggar/area/forest1.c
// Generated by Roommaker Fri Mar 22 01:41:48 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("竹林");
	ob->set_long( @LONG_DESCRIPTION
你身处在一片绿油油的竹林里,这里很安静,用来读书的好地方。
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exit_suppress", ({ 
		"north" }) );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/north11", 
		"north" : "/d/eastland/beggar/area/forest2" ]) );
	ob->reset();
}
