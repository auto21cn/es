// File: /d/eastland/saulin_temple/hallway2.c
// Generated by Roommaker Wed Nov 22 22:51:17 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
������һ�������ϣ����Զ���̨ͥ���ߣ�����ɮ�����������֯������
����û������ȥ�������ܵĻ��������ºų�ǧ�Ȱ�Ժ���������ĳ��Ȳ�֪��
���٣���ɵ�С����·�����������������ȥ��
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/hallway3", 
		"west" : "/d/eastland/saulin_temple/hallway1" ]) );
	ob->reset();
}