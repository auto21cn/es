#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long( @LONG
这是一处透著些许微光线的阴暗洞穴。从上面灌进来的风在地上绕著圈圈形成
一个小小的龙卷风旋即又飞起以其利锐的前锋刮过墙壁发出「咻咻咻」的声音；在
空中，好似有人正在对著你嘲笑并且发出桀桀的笑声，那异样的感觉，不禁令你毛
骨悚然冷汗直流；忽然，不知道你踢到什麽东西，低头一看，竟然是一堆白骨！看
来这不是个良善的地方，你还是快离开这里为妙。
LONG
	);
	set( "exits", ([ 
       	     "up" : SAREA"room_h",
        ]) );
	reset();
}
int clean_up() { return 0; }

