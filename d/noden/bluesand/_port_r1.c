// File: /d/noden/bluesand/port_r1.c
// Generated by Roommaker Mon Dec  4 22:09:51 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����·");
	ob->set_long( @LONG_DESCRIPTION
������������ɳ����Ҫ�Ľֵ�������·�ϡ�����ı�����һƬ���д�
������ɫϸ���ɳ̲����ͷ����Ķ�����Զ�����ϱ�����ɳ��������ˮ��
�ưɣ�˳������·���������뿪��ɳ�ۡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "bluesand" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/bluesand/port_r2.c", 
		"south" : "/d/noden/bluesand/pub.c", 
		"west" : "/d/noden/bluesand/port_r0.c", 
		"north" : "/d/noden/bluesand/beach" ]) );
	ob->reset();
}