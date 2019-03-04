#include <hole.h>

inherit ROOM;

void create()
{
	object abon;
	::create();
	set_short( "王宫寝室" );
	set_long(@LONG
这间房间是蜥蜴人剑术师『亚邦』的住所。『亚邦』在这个国度
里负责教授年轻一代的蜥蜴人剑法。
LONG
		);
	set( "exits",([
			"northeast" : HOLE"hole36",
			]) );
	abon = new( HMONSTER"swordman" );
	abon->move( this_object() );
	reset();
}
