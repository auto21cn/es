// File: /d/eastland/saulin_temple/forest7.c
// Generated by Roommaker Wed Nov 22 23:27:17 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���е�С��");
	ob->set_long( @LONG_DESCRIPTION
������һ��С���ϣ��ྻ��С����ʾ���������߹����ϰϰ��΢��
�����������㴵����ֻ�мżŵ����ܳ��������Ұ��Ʈ�㣬����������һ
����������Ӱ��������
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/saulin_temple/rain_temple", 
		"south" : "/d/eastland/saulin_temple/forest6" ]) );
	ob->set( "objects", ([ 
		"fly2" : "/d/noden/elf/monster/rabbit", 
		"fly" : "/d/noden/elf/monster/rabbit" ]) );
	ob->reset();
}