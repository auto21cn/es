#include <hole.h>

inherit ROOM;

void create()
{
	object bulansido;
	::create();
	set_short( "领袖寝室" );
	set_long(@LONG
这间房间是素有『战神』称号的蜥蜴人领袖『古兹曼』的住所。
LONG
		);
	set( "exits",([
			"up" : HOLE"hole44",
			]) );
	bulansido = new( HMONSTER"leader" );
	bulansido->move( this_object() );
	reset();
//#include <replace_room.h>
}

int clean_up(){ return 0; }
