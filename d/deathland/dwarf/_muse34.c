// File: /d/deathland/dwarf/muse34.c
// Generated by Roommaker Thu Nov 23 20:03:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("һ�������ĵط�");
	ob->set_long( @LONG_DESCRIPTION
������, ��ֻ������ˮ�ĵδ���, ����������������һ�����ʵĸо�, ��������
��������Դһ��.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/deathland/dwarf/muse33", 
		"north" : "/d/deathland/dwarf/muse35" ]) );
	ob->reset();
}