// File: /d/eastland/8,5.east.c
// Generated by Roommaker Thu Jan 27 03:14:49 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("·��");
	set_long( @LONG_DESCRIPTION
����������һ������·�ڣ�·����һ������ƣ�����д���������ŷɴ��ؿ�վ��
����ᰳǵ����ž�����Ķ��߲�Զ��������һ����ֱ�Ĵ��ͨ���Ϸ����Ĺ��ǣ�����
�ĵ�· ����һƬ��ԭͨ����÷��
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
		"south" : "d/eastland/8,6.east", 
		"north" : "d/eastland/8,4.east", 
		"west" : "d/eastland/7,5.east", 
		"east" : "/d/eastland/easta/westgate" ]) );
	set( "original", "d/eastland/8,5" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}

void init()
{
	if( !find_object("/d/std/cloud/airship_pegasus") )
		"/d/std/cloud/airship_pegasus"->frog();
}