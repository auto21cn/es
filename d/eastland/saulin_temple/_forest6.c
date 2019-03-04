// File: /d/eastland/saulin_temple/forest6.c
// Generated by Roommaker Wed Nov 22 23:27:05 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("林中的小径");
	ob->set_long( @LONG_DESCRIPTION
你走在一条小径上，洁净的小径显示经常有人走过这里，习习的微风
穿过林梢向你吹来，只有寂寂的四周虫鸣鸟啼和野花飘香，小径向南北方
蜿蜒而去。
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/saulin_temple/forest5", 
		"north" : "/d/eastland/saulin_temple/forest7" ]) );
	ob->reset();
}
