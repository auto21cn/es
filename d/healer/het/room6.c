#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;
create()
{
	::create();
	set_short("笼子");
	set_long(@C_LONG
这是一个阴暗的笼子, 地上到处都是血迹和一些残缺的尸体,
空气中浓浓的血腥味, 阴暗处似乎有双眼睛瞪著你, 你不禁害怕起来。
C_LONG
	);
	set("exits",([
		"out" : WANG"room2",
	]));
        create_door("out","enter",([
                "keyword" : ({"iron door","door"}),
                "name" : "iron door",
                "c_name" : "铁门",
                "c_desc" : "这是一扇厚重的铁门, 门下有个很小的小开口",
                "status" : "locked",
		"lock"	: "WANG"
        ]) );
	reset();
}
