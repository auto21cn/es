// File: /d/eastland/saulin_temple/stone_path2.c
// Generated by Roommaker Wed Nov 22 23:09:35 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ʯ��С��");
	ob->set_long( @LONG_DESCRIPTION
��������������ǧ�Ȱ�Ժ���ͨ���ϣ�ĥ���Բ��⻪��ʯ�����ԵĶ���
��ҫ�����µ��ƾ���ʷ��ң�������������֣����ڻ�����ǽ����ɮ��ȥ���ο�
��ӣ��㲻���г���֮�롣�����ǽ����ã������ǲؾ���
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/book_temple1", 
		"north" : "/d/eastland/saulin_temple/river_side1", 
		"south" : "/d/eastland/saulin_temple/river_side2", 
		"west" : "/d/eastland/saulin_temple/classroom" ]) );
	ob->reset();
}