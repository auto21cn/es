// File: /d/noden/drow/r41.c
// Generated by Roommaker Mon Nov 27 14:18:04 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��ʪ��ˮ��");
	ob->set_long( @LONG_DESCRIPTION
������һ����ˮ�������ϻ�ˮ��Լ��ߣ�������һ��޹�˵�ùζ��
ˮ���쳣��������Ʈ��һЩ�����������ǵ����ϵ����Ҷ��ģ�����ǽ��
��ʱ����ˮ�գ��εδ�����������ͨ������ɻ�������
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"northwest" : "/d/noden/drow/r39", 
		"east" : "/d/noden/farwind/tunnel3.c", 
		"west" : "/d/noden/drow/r40" ]) );
	ob->set( "objects", ([ ]) );
	ob->reset();
}