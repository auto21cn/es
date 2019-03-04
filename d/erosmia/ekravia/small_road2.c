#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("end of a small road","小路尽头");
	set_long(@CLong
小路在这里中止, 西边的果园挡住了去路。一户农家就在小路北边,
你可以看到农家门口的空地上几只鸡鸭悠闲地走来走去。
CLong
);
	set("exits", ([
		"east"		: HERE"small_road1",
		"north"		: HERE"farmer_house"
		]));
	set( "objects", ([
		"goose1"	: MOB"goose",
		"goose2"	: MOB"goose",
	]) );
	reset();
}
