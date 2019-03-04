#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "点子中心" );
	set_long(
			"这个地方是让那些有新点子，但是不知道怎麽将它实作出来，或是\n"
		"没有时间写的巫师们提供其它巫师点子的地方。如果这个点子是你自己\n"
		"要做的，请留言在企划室( 往东走就是 )。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/planning"
	]) );

	// Cause the idea_board to load
	call_other( "/d/wiz/idea_board", "???" );
}
