// File: /d/eastland/legend/lake/village17.c
// Generated by Roommaker Thu Mar 21 17:29:00 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����·");
	ob->set_long( @LONG_DESCRIPTION
�����������ĵ�·�ϣ�ӭ����������һ��ŨŨ���ȳ�ζ���ڵ��ϣ��ݺύ��
��Ѫˮ��Ǭ��С�ӣ�һ���Ų�Ӭ��������춸��õ������ϣ���ʱ�������˵�������
�ް���������գ������Ŵغ���һֻֻ����������צ��Ұ�ޣ�Ұ������ݺݵص���
�㣬���������˵���������ɣ������ɣ��ҵ�ʳ��������ϱ���һ�Ѻ���ͬ�߶�
��Ұ�ݣ���·�������������ꡣ
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/eastland/legend/lake/village18", 
		"south" : "/d/eastland/legend/lake/village10" ]) );
	ob->set( "objects", ([ 
		"girl#1" : "/d/eastland/legend/monster/girl", 
		"boy#1" : "/d/eastland/legend/monster/boy", 
		"boy#2" : "/d/eastland/legend/monster/boy" ]) );
	ob->reset();
}