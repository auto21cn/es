// File: /d/eastland/beggar/area/master_roomw.c
// Generated by Roommaker Thu Mar 21 18:11:49 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�����Ʒ�������");
	ob->set_long( @LONG_DESCRIPTION
�����ǡ����Ʒ������������ƫ����
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/master_room.c" ]) );
	ob->reset();
}
