// File: /d/eastland/saulin_temple/river_side1.c
// Generated by Roommaker Wed Nov 22 23:09:49 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��Ե�ݵ�");
	ob->set_long( @LONG_DESCRIPTION
������һƬ�ݵ��ϣ�������һƬ���֣�����ɽ�紵�ӡ����������⣬û
��һ�㳾�������������ľ���ɭ����Ϣ���������ÿһ������������������
�����ʱ�������׵�һ������ǣ�����ſ��������������ѵõ���Ȼ֮����
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/river_side3", 
		"south" : "/d/eastland/saulin_temple/stone_path2" ]) );
	ob->reset();
}