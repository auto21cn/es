// File: /d/deathland/city/g7.c
// Generated by Roommaker Sat Nov 11 15:20:21 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("Ӣ��Ĺ��");
	ob->set_long( @LONG_DESCRIPTION
�����ǰ���Ӣ�۵�Ĺ��,Ĺ���������һλ�ݺ�ɳ����Ӣ��.��һ��Ĺ���ı�����
д��: һλ���˾������޵�Ӣ��.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"east" : "/d/deathland/city/g6", 
		"north" : "/d/deathland/city/gb", 
		"west" : "/d/deathland/city/g8" ]) );
	ob->set( "objects", ([ 
		"guard" : "/d/deathland/monster/guard05" ]) );
	ob->set( "pre_exit_func", ([ 
		"north" : "to_north" ]) );
	ob->reset();
}
