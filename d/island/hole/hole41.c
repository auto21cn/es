#include <hole.h>

inherit ROOM;

void create()
{
	object arthur;
	::create();
	set_short( "王宫寝室" );
	set_long(@LONG
这间房间是蜥蜴人骑士团团长『亚瑟』的住所。『亚瑟』目前是这个
国度里骑士军团的领导者。
LONG
		);
	set( "exits",([
			"east" : HOLE"hole42",
			]) );
	arthur = new( HMONSTER"colonel" );
	arthur->move( this_object() );
	reset();
}

int clean_up(){ return 0; }
