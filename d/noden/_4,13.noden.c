// File: /d/noden/4,13.noden.c
// Generated by Roommaker Tue Nov 21 00:41:18 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ƽԭ");
	ob->set_long( @LONG_DESCRIPTION
����������һƬƽ���ϣ��������ݵ�׺��һЩ��ʯ�����￪������
Ұʹ���������ؿ���Զ���ľ��������ħ��֮������Ħ�Ǵ�ǡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/moyada/w_gate", 
		"west" : "d/noden/3,13.noden", 
		"north" : "d/noden/4,12.noden", 
		"south" : "d/noden/4,14.noden" ]) );
	ob->set( "original", "d/noden/4,13" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 4 );
	ob->set( "y_coordinate", 13 );
	ob->reset();
}