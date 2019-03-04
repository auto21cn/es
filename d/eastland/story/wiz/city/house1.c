#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("大国师官邸");
	set_long( @LONG
这里是「巫城国」护国师居住的官邸。官邸里雕梁画栋，琉璃天顶，彩壁朱绘
，白银器皿，珊瑚制椅具，前面一张虎背玉座，後面八骏马屏风，端的是一脉珠光
宝气，金碧辉煌不可而语。旁边各有甬道可以通往内堂。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "out" : SCITY"ne1"
        ]) );
        set( "objects", ([
           "elder" : SWMOB"wiz_elder1",
        ]) );
	reset();
}
