#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "绿苔广场" );
	set_long(@LONG
洞穴到这儿似乎变得宽阔多了，两旁墙壁上挂著许多火把，使人能
很清楚的看到这个大石洞中的一切。哦～～！原来这儿是蜥蜴人平时聚
会的广场，由於石壁上长满了淡绿色的青苔，故得名「绿苔广场」。
LONG
		);
	set( "light",1 );
	set( "exits",([
			"east"  : HOLE"hole24",
			"south" : HOLE"hole22",
			"north" : HOLE"hole20"
			]) );
	reset();
#include <replace_room.h>
}
