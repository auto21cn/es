
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "钟乳石洞穴" );
	set_long(@LONG
你忽然来到一处潮湿的洞穴，叮叮咚咚的水声由洞穴深处传来。
猛抬头一看，几根将近三尺的钟乳石上，忽然落下几滴清凉的水珠打
在你身上。刹时间你觉得彷佛置身仙境。
LONG
		);
	set( "exits",([ 
			"northwest" : HOLE"water20",
			"south" : HOLE"water22",
		]) );
	reset();
	
}