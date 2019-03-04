#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「巫咸国」西门");
	set_long( @LONG
这里是「巫咸国」的西门，城门两旁耸立著高墙，墙底则是布满青苔的基石，
另外在城楼上还刻著「巫咸国」三个漆金大字。城墙上，卫兵轮流交替，个个雄纠
纠气昂昂，威武挺拔，正在捍卫著「巫咸国」的安全。由这里往东则进入城中，西
边是个大湖泊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	   "east" : SCITY"ww",
        ]) );
        set("objects", ([
           "guard#1" : SWMOB"wiz_guard1",
           "guard#2" : SWMOB"wiz_guard1",
        ]) );
	reset();
}
