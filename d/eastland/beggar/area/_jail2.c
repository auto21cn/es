// File: /d/eastland/beggar/area/jail2.c
// Generated by Roommaker Thu Mar 21 18:10:09 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��н���塻����");
	ob->set_long( @LONG_DESCRIPTION
�����������˼��εĵص���һ�㡣�������ض��ǰ�ɭɭ�ġ���, ��������һ��
����ǽ���ϵ�ľ�崲��
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"bed" : "һ�ż�򵥵���ľ����\n", 
		"bone" : "�������˵Ĺ�ͷ��\n" ]) );
	ob->set( "exits", ([ 
		"up" : "/d/eastland/beggar/area/jail1.c" ]) );
	ob->set( "objects", ([ 
		"prisoner" : "/d/eastland/beggar/monster/prisoner" ]) );
	ob->reset();
}