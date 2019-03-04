// File: /u/m/mad/room/grave_yard4.c
// Generated by Roommaker Tue May 23 17:25:38 1995

#include "mad.h"

inherit ROOM;

void create()
{
	::create();
   set_short( "墓地" );
	set_long( @LONG_DESCRIPTION
这□是坟场的一处尽头, 四周仍然是高大浓密的树木,
而且除了刚才通向这儿的小径, 到处布满了杂草荆棘, 令你
寸步难行。当你扫视这□时, 你看到所有的墓碑(headstone)
不是歪斜倾颓, 就是损坏不堪辨认; 但是你竟然看到在角落
处竟有一个完整的墓碑!
LONG_DESCRIPTION
	);

   set( "c_item_desc", ([
     "headstone" : "一大块青石刻成的石碑, 可惜上面的字迹已斑驳不堪辨认。\n"
        ]) );
   set( "objects", ([
            "father" : IANMOB"false_father" ]) );
	set( "exits", ([ 
            "northeast" : IAN"grave_yard1" ]) );
	reset();
}
