// File: /d/deathland/dwarf/village_02.c
// Generated by Roommaker Thu Nov 23 19:13:40 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ͨ�����˵Ĵ����С·");
	ob->set_long( @LONG_DESCRIPTION
��С·��ͨ�����˵Ĵ����Ψһ;��,���Ǳ�����һ���ܴ�ľ�Ӫ.������\��
��İ���ʿ������ѵ��������.ϣ����û���ڰ��˹���û�����κεĻ���,������
�ò�Ҫ����ǰ��.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/deathland/dwarf/village_03", 
		"south" : "/d/deathland/dwarf/village_01" ]) );
	ob->reset();
}