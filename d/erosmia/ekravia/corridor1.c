#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("走廊");
	set_long(
@CLong
这里是旅店中的一角, 由这里往北可以回到大厅。西边则是一家热闹的
小酒吧。
CLong
);
	set("exits", ([
		"west"		: HERE"bar",
		"north"		: HERE"tavern",
		]));
}
