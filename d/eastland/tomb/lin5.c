#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("竹林");
	set_long( 
@C_LONG_DESCRIPTION
你进入了一片竹林 !! 实在无法想像在地底下怎麽会有一片如此大的竹林，而且还长的
如此茂盛，真是令人吃惊。微风轻轻吹来，令你觉得十分舒服。你看到这些竹子的根部都被
一种奇异的光芒包围著，大概这就是它们能在这儿存活下来的原因。在东边有一幢精致的小
屋，你想也\许\可以在那儿找到为何地底下会存在这样一个地方的原因。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"south" : TOMB"/lin4",
		"east" : TOMB"/house1",
		"west" : TOMB"/lin6" ]) ); 
	reset();	
#include <replace_room.h>
}

