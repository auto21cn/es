// File: /d/eastland/dragon/cave22.c
// Generated by Roommaker Sat Nov 25 14:04:27 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���³�");
	ob->set_long( @LONG_DESCRIPTION
�˴���һ�����ϵĵ��³ǣ��˴���ǽ�ڼ��ذ嶼���Դ���ʯ����ɵ�ͬʱǽ�����м�
ֻ���ȼ���������컨����������\�����ֵ�С�ף�Ӧ���Ǵ˵��³ǵ�ͨ��ף������ܵ�
���￴���˵رض���ǧ�����ϵ���ʷ�����Ǿ��������ҿ������£��㲻�ò�����������
�˵Ľ����������
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/dragon/cave16", 
		"west" : "/d/eastland/dragon/cave24", 
		"north" : "/d/eastland/dragon/cave23" ]) );
	ob->reset();
}