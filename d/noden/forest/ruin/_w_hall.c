// File: /d/noden/forest/ruin/w_hall.c
// Generated by Roommaker Mon Dec  4 21:31:01 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����");
	ob->set_long( @LONG_DESCRIPTION
�������ɽ��֮�С����ﲢ���Ƿǳ��ڰ�, �ռ�Ҳ�൱�ع����Ȼ
�����Զ, ����ʯ�Ƶĵذ塢ǽ�����컨����ʱʱ�ɼ������ĵ��, ����
�������Ǹ��������������������������������ࡣ
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/forest/ruin/hall", 
		"north" : "/d/noden/forest/ruin/nw_hall", 
		"south" : "/d/noden/forest/ruin/sw_hall" ]) );
	ob->reset();
}