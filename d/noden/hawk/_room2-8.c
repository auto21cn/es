// File: /d/noden/hawk/room2-8.c
// Generated by Roommaker Mon Sep 30 14:37:05 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����ս�õ�·");
	ob->set_long( @LONG_DESCRIPTION
�ߵ���������ֿ�ʼ�е�һ�ɳ��ص�ѹ�����������˳������ˣ�����
ȴ������������Ѳ�ߵ�ʿ�����䱸ɭ�ϵ���������е����������ڡ�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"southwest" : "/d/noden/hawk/room2-7", 
		"northup" : "/d/noden/hawk/room2-10", 
		"southeast" : "/d/noden/hawk/room2-11" ]) );
	ob->set( "objects", ([ 
		"soldier3" : "/d/noden/hawk/monster/fighter", 
		"soldier" : "/d/noden/hawk/monster/soldier", 
		"soldier2" : "/d/noden/hawk/monster/soldier" ]) );
	ob->reset();
}