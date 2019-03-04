// File: /d/eastland/12,1.east.c
// Generated by Roommaker Wed Nov 22 13:08:08 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("道路");
	ob->set_long( @LONG_DESCRIPTION
你现在正走在一条碎石铺成的道路上，道路向南、北方延伸。路旁的草
地上长著一些不知名的野花及野草。在你的前方是一座雄伟的关门口，城门
上刻著三个大字。远远的看不清楚写些什麽。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"west" : "d/eastland/11,1.east", 
		"north" : "/d/eastland/mumar/gate", 
		"south" : "d/eastland/12,2.east" ]) );
	ob->set( "original", "d/eastland/12,1" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 12 );
	ob->set( "y_coordinate", 1 );
	ob->reset();
}
