// File: /d/eastland/goomay/kwi_yi2.c
// Generated by Roommaker Thu Nov 23 18:35:22 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����������");
	ob->set_long( @LONG_DESCRIPTION
���߽������õ����ã�������ĽŲ���Щ���ֵ�ߺ��������Զȥ����
���ģ�һ·�Ͼ�ƿ�ơ�ȴԽ��Խ�࣬���Ҹ�����������������ę́�ơ���
������Һ����³�������ѾƵȵ�..�������ǲ���ʤ������������������
��һ���Ǹ��þ�Ʒ�Ƶ�ר�ҡ�
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/goomay/kwi_yi" ]) );
	ob->set( "objects", ([ 
		"master" : "/d/eastland/goomay/monster/master_jau" ]) );
	ob->reset();
}