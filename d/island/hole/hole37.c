#include <hole.h>

inherit ROOM;

void create()
{
	object akaba;
	::create();
	set_short( "王宫寝室" );
	set_long(@LONG
这间房间是蜥蜴人大将军阿卡巴的住所。阿卡巴在这个国度里可
以算是一等一的战士，手上的双斧不知道击败多少好汉。
LONG
		);
	set( "exits",([
			"southwest" : HOLE"hole36",
			]) );
	akaba = new( HMONSTER"imperator" );
	akaba->move( this_object() );
	reset();
}

int clean_up() { return 0; }
