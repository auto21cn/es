#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "地下王宫" );
	set_long(@LONG
你现在所站的的位置是蜥蜴人王宫的第一层，不过怎麽看都不像
是个达官贵人的栖息场所，倒不如说是个洞穴更为恰当；或许这是因
为蜥蜴人天生就比较不讲究居住环境所造成的。
LONG
	);
	set( "exits",([
			"northwest" : HOLE"hole35",
			"northeast" : HOLE"hole37",
			"southwest" : HOLE"hole39",
			"southeast" : HOLE"hole38",
			]) );
	reset();
#include <replace_room.h>
}
