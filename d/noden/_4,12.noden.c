// File: /d/noden/4,12.noden.c
// Generated by Roommaker Tue Nov 21 00:40:58 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɭ��");
	ob->set_long( @LONG_DESCRIPTION
������������һ��ɭ��֮�У���ï����ľɢ����һ�ɵ����ġ�
��ˬ���˵���Ϣ��������������ּ�С��֨֨���������������ŵ�
��һ����Ҷ����������վ���ĵط���
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/5,12.noden", 
		"west" : "d/noden/3,12.noden", 
		"north" : "d/noden/4,11.noden", 
		"south" : "d/noden/4,13.noden" ]) );
	ob->set( "original", "d/noden/4,12" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 4 );
	ob->set( "y_coordinate", 12 );
	ob->reset();
}