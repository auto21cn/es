// File: /d/eastland/saulin_temple/hallway12.c
// Generated by Roommaker Wed Nov 22 22:49:06 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
������һ�������ϣ����Զ���̨ͥ���ߣ�����ɮ�����������֯������
����û������ȥ�������ܵĻ��������ºų�ǧ�Ȱ�Ժ���������ĳ��Ȳ�֪��
���٣���ɵ�С����·�������Ϸ�����һ�����ȣ�����������
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/hallway11", 
		"north" : "/d/eastland/saulin_temple/back_temple", 
		"south" : "/d/eastland/saulin_temple/hallway13" ]) );
	ob->reset();
}