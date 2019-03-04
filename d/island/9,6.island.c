// File: 9,6.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @LONG_DESCRIPTION
����һƬ�ɸ������Ƶľ�ľ�����ɵ������������ľ���ܣ���ʹ�㼸
���������������ʲ����ڣ�Ҳ����������ǰ���кܶ����صĴ�˵��
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,6.island", 
		"north" : ISLAND"9,5.island", 
		"east"  : ISLAND"10,6.island",
		"south" : ISLAND"9,7.island",
		]) );
	set( "original", ISLAND"9,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 6 );
        set( "no_monster" , 1 );
        set( "objects",([
                 "c1":IMON"spec_crow",
                 "c2":IMON"spec_crow"
                     ] ));
	reset();
}
