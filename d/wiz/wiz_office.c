#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "巫师办公室" );
	set_long( @LONG
这里虽然是巫师们办公的地方，但是巫师们平常大部份都呆在
自己的工作室。这里主要是用来放一些巫师的留言板、工具( 玩具
 )等，称作『巫师交谊厅』倒比较恰当。
    往北走你可以回到巫师大厅，在你的西边是企划室，东边是品
管部，往南，则是大巫师的办公室。
LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"north"	:	"/d/wiz/wiz_hall",
		"south"	:	"/d/wiz/arch_office",
		"west"	:	"/d/wiz/planning",
		"east"	:	"/d/wiz/qc-request"
	]) );

	// Cause the wizard board to load
	call_other( "/d/wiz/wiz_board", "???" );
}
