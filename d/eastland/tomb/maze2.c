#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下通道");
	set_long( 
@C_LONG_DESCRIPTION
你现在来到一个宽阔的地下通道，四周的墙壁是用上好石砖砌成的，地上积了一层浅浅
的灰，似乎已经有好一段时间没有人进来过。通道深处吹来一阵阵的冷风，你的经验告诉你
必须打醒十二万分的精神来面对未知的危险。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/maze3", 
		"south" : TOMB"/maze1",
		"east"  : TOMB"/maze1",
		"west"  : TOMB"/maze1" ]) );
	set( "objects", ([ 
		"cockroach#1" : MOB"/cockroach", 
		"cockroach#2" : MOB"/cockroach" ]) );
	reset();
#include <replace_room.h>
}

