#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set( "light", 1 );
	set_short( "回廊" );
	set_long(@CLONG
这里是王宫中的一处回廊，在你的西边是国王的议事厅，东边是国王
的图书室。一座雕饰精美的楼梯通往王宫二楼。
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"throne_room",
		"east" : NODANIA"royal_lib",
		"up" : NODANIA"upstair_1"
	]) );
	create_door( "east", "west", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "橡木门",
		"status" : "locked",
		"c_desc" : "一扇雕饰华丽的橡木门，。\n",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
}
