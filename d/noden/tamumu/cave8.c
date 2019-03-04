// File: /d/noden/tamumu/cave8.c
// Generated by Roommaker Wed Dec 15 07:38:41 1993

#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("洞穴");
	set_long( @C_LONG_DESCRIPTION
这里的空气不但潮湿，而且还隐隐夹杂著一股臭味，这使你想起远风镇老铁匠
店里的地下室，不过味道有点不同....这里的味道好像是尸体腐败的味道，你连呼
吸都不敢太用力，以免被这种可怕的味道呛昏。东边的空气似乎比较新鲜，西边隐
约有一些亮光。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : "/d/noden/tamumu/jail2", 
		"west" : "/d/noden/tamumu/cave9", 
		"east" : "/d/noden/tamumu/cave7" ]) );
	create_door( "north", "south", ([
		"keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "铁门",
		"c_desc" : "一扇厚实的铁门，上面有一道凹槽",
		"status" : "locked",
		"lock" : "TAMUMU_JAIL1"
	]) );
	reset();
}
