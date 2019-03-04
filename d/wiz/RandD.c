#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "研发部" );
	set_long(
			"这里是东方故事的研发部，用来讨论一些和 mudlib 介面，函数等\n"
		"技术性较高的研发项目。若是新增了什麽函数或定义了新的属性也会在\n"
		"这里发布。往东走可以回到大巫师办公室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/arch_office"
	]) );

	// Cause the RD_board to load
	call_other( "/d/wiz/RD_board", "???" );
}
