// File: /d/eastland/goomay/coliseum3.c
// Generated by Roommaker Thu Nov 23 18:54:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�䶷���᳡");
	ob->set_long( @LONG_DESCRIPTION
������ÿһ��ϰ������������ĳ����أ����µ�һ�䶷���᳡������Ƭ
�����Ļ᳡�ϣ�������\���������Ӻͼ�����ӣ��˿�������\�����ڳ��ϣ�����
��\�������ȭ������������ʱ������
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "PK_ZONE", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/coliseum1", 
		"west" : "/d/eastland/goomay/coliseum2", 
		"south" : "/d/eastland/goomay/coliseum6", 
		"north" : "/d/eastland/goomay/coliseum6" ]) );
	ob->reset();
}