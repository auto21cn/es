// File: /d/eastland/goomay/ruin4.c
// Generated by Roommaker Thu Nov 23 18:44:49 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
������һ���İ���խ����Զ���������Ͻ������ܽǵ�������˿��
���Ļҳ���ʹ����һ��ʱ�䶳���˵ĸо�����Ū���Ҷ���СС��ȱ�ڣ�
����һ����С·��һ�����Ȯ�ͼ���������ķ����л��졣
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/goomay/hunter_house", 
		"north" : "/d/eastland/goomay/ruin5", 
		"south" : "/d/eastland/goomay/ruin2" ]) );
	ob->reset();
}