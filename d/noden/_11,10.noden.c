// File: /d/noden/11,10.noden.c
// Generated by Roommaker Tue Nov 21 00:23:24 1995

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
		"east" : "d/noden/12,10.noden", 
		"west" : "d/noden/10,10.noden", 
		"north" : "d/noden/11,9.noden", 
		"south" : "d/noden/11,11.noden" ]) );
	ob->set( "objects", ([ 
		"beetle#3" : "/d/noden/monster/beetle", 
		"beetle#2" : "/d/noden/monster/beetle", 
		"beetle#1" : "/d/noden/monster/beetle" ]) );
	ob->set( "original", "d/noden/11,10" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 11 );
	ob->set( "y_coordinate", 10 );
	ob->reset();
}