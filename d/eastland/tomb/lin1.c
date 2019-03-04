#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("竹林");
	set_long( 
@C_LONG_DESCRIPTION
你进入了一片竹林 !! 实在无法想像在地底下怎麽会有一片如此大的竹林，而且还长的
如此茂盛，真是令人吃惊。微风轻轻吹来，令你觉得十分舒服，有点儿昏昏欲睡。你看到这
些竹子的根部都被一种奇异的光芒包围著，大概这就是它们能在这儿存活下来的原因。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"north" : TOMB"/lin6",
		"south" : TOMB"/lin2",
		"east" : TOMB"/lin4",
		"west" : TOMB"/square5" ]) ); 
	reset();	
#include <replace_room.h>
}

