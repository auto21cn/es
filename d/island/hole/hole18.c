#include <hole.h>

inherit ROOM;
void create()
{
	::create();
	set_short( "湿地" );
	set_long(@LONG
在这个巨大岩盘之下，竟然是一片十分潮湿的苔地，沼气弥漫，
呛得几乎都不能呼吸了。洞穴两旁的青苔也因为缺乏阳光的照射，而
呈现苍白的颜色，不禁令人怀疑：这里真的有人居住吗？
LONG
);
	set( "exits",([
			"northeast" : HOLE"hole17",
			"south" : HOLE"hole19"
			]) );
	reset();
#include <replace_room.h>
}
