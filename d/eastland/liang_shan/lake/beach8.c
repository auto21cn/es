#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖滨");
	set_long( @C_LONG_DESCRIPTION
你来到一片平坦的沙地，柔细的黄沙使得你的身後，留下一行深深的足印，偶尔
清风吹起，湖面泛起阵阵涟漪，不禁令人有出世之想，沙地旁的草丛长满了不知名的
野花。北边不远似乎有几户人家。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"beach7",
		"north" : TROOM"village1" ]) );
	reset();
}
