// File: /d/deathland/island/swamp04.c
// Generated by Roommaker Thu Nov 23 19:43:29 1995

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
		"southwest" : "/d/deathland/island/swamp03", 
		"east" : "/d/deathland/island/swamp08", 
		"south" : "/d/deathland/island/swamp05" ]) );
	ob->reset();
}