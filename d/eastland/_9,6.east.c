// File: /d/eastland/9,6.east.c
// Generated by Roommaker Wed Nov 22 13:19:52 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ƽԭ");
	ob->set_long( @LONG_DESCRIPTION
����������һƬƽ���ϣ��������ݵ�׺��һЩ��ʯ�����￪������
Ұʹ���������ؿ���Զ���ľ��
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/eastland/10,6.east", 
		"south" : "d/eastland/9,7.east", 
		"north" : "/d/eastland/easta/southgate", 
		"west" : "d/eastland/8,6.east" ]) );
	ob->set( "objects", ([ 
		"peacock1" : "/d/eastland/monster/peacock", 
		"peacock2" : "/d/eastland/monster/peacock" ]) );
	ob->set( "original", "d/eastland/9,6" );
	ob->set( "virtual_server", "/d/eastland/virtual/east_server" );
	ob->set( "x_coordinate", 9 );
	ob->set( "y_coordinate", 6 );
	ob->reset();
}