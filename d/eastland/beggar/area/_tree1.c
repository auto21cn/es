// File: /d/eastland/beggar/area/tree1.c
// Generated by Roommaker Mon Jul 22 18:05:13 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��֦");
	ob->set_long( @LONG_DESCRIPTION
����������һ��Ũ�ܵ�������,�����֦��ס��̫��,�����������������Щ��
��,���������ȥ͸͸����
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"down" : "/d/eastland/beggar/area/s4w1" ]) );
	ob->set( "objects", ([ 
		"beetle2" : "/d/eastland/beggar/monster/beetle", 
		"swordman" : "/d/eastland/beggar/monster/occult_swordman", 
		"beetle1" : "/d/eastland/beggar/monster/beetle" ]) );
	ob->reset();
}