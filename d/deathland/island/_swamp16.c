// File: /d/deathland/island/swamp16.c
// Generated by Roommaker Thu Nov 23 19:47:44 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�Ұ�֮��������");
	ob->set_long( @LONG_DESCRIPTION
һ�������������, �������ƺ��������µ��������������ȥ, �����С�Ľ���
���ÿһ��. Խ�����������ˮ��Խ��, �����������Ҳ����������ȫ����ס��. ��
�������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ����������������.

LONG_DESCRIPTION
	);

	ob->set( "exit_invisble", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/deathland/island/swamp20", 
		"west" : "/d/deathland/island/swamp12" ]) );
	ob->set( "objects", ([ 
		"plant" : "/d/deathland/monster/plant02" ]) );
	ob->reset();
}