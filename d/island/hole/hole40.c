#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "地下王宫" );
	set_long(@LONG
你现在所站的的位置是蜥蜴人王宫的第二层，不过怎麽看都不像
是个达官贵人的栖息场所，倒不如说是个洞穴更为恰当；或许这是因
为蜥蜴人天生就比较不讲究居住环境所造成的。
LONG
	);
	set( "exits",([
			"up" : HOLE"hole38",
			"north" : HOLE"hole42",
			]) );
	reset();
#include <replace_room.h>
}
