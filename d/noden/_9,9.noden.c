// File: /d/noden/9,9.noden.c
// Generated by Roommaker Tue Nov 21 00:47:26 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("������Ͽ��");
	ob->set_long( @LONG_DESCRIPTION
�����ǿ�����Ͽ�ȣ����ʵ�ɽ����ס���Ϸ���������ͨ·������
�ǽ�ͨŵ������������ͨ����Ҫͨ������ǰ���ﱾ����һ����������
�����գ������Դ�ħ��ʦ�Ƿ����˴��ͷ����İ���֮�ᣬ����ľ���
��ֵ��û��������Ҫ�ˡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "d/noden/10,9.noden", 
		"west" : "d/noden/8,9.noden" ]) );
	ob->set( "objects", ([ 
		"bandit 2" : "/d/noden/monster/bandit" ]) );
	ob->set( "original", "d/noden/9,9" );
	ob->set( "virtual_server", "/d/noden/virtual/noden_server" );
	ob->set( "x_coordinate", 9 );
	ob->set( "y_coordinate", 9 );
	ob->reset();
}