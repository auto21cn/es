#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "旧岗哨" );
	set_long(@LONG
这儿留下一些旧的军用装备和碉堡，目前已经废弃不用了。原因是
从前驻守在此地的士兵常常会离奇的死亡，而且死状奇惨，像是全身的
体液都被吸乾似的；由於苦苦无法查出原因，所以便决定将岗哨往後撤
，以免意外再度发生。
LONG
	);
	set( "exits",([
			"southwest" : HOLE"hole29"
			]) );
	reset();
#include <replace_room.h>
}
