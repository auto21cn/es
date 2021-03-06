
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("On the Plain", "田野");
	set_long( @C_LONG_DESCRIPTION
你站在一望无际的田野上, 四周是美丽的小麦田。风吹过青翠的麦草,
扬起一阵阵绿色的波浪。北边的远方, 一座美丽的城镇悠雅地斜倚於山丘
旁。正好面对著你南边不远处, 缓缓流过的大河。
C_LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north" : "/d/erosmia/ekravia/south_gate", 
		"east" : "/d/erosmia/11,11.erosmia", 
		"west"	:"/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/10,11" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 11 );
	reset();
}
