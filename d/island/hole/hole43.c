#include <hole.h>

inherit ROOM;

void create()
{
	object rasoda;
	::create();
	set_short( "王宫寝室" );
	set_long(@LONG
这间房间是蜥蜴人祭司『拉索达』的住所。『拉索达』目前是这个
国度负责魔法方面的一切事务。
LONG
		);
	set( "exits",([
			"west" : HOLE"hole42",
			]) );
	rasoda = new( HMONSTER"poutiff" );
	rasoda->move( this_object() );
	reset();
//#include <replace_room.h>
}
