// File: /d/eastland/beggar/area/s1w1.c
// Generated by Roommaker Thu Mar 21 18:07:11 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��н���塻�㳡");
	ob->set_long( @LONG_DESCRIPTION
����һ��Ƭ��ɰ�㳡, ��Ϊ��ؤ����ӳ��ڴ˴����书,���Ե����Եù�ͺ
ͺ��һ���Ӳ�Ҳû�С���ʱ���εĺܴ�Ю��������Ļҳ�,������ÿ���ϱߵĸ�
ɽ��������ɽ�硻,������۾�����������ǡ�ؤ��ⶨ��һЩˮ�����ֵĹ���
, ���Ǵ���ȱ����һ��Ƭ�յؿ��Թ���������ϰ,����ÿ�������ֵ��Ƥ�Ĺ�����
�����˷���, ��Ǻ����ǻ��ǵü���������ȥ�����������ϱ��ǹ㳡�ļ�������,
�����ǵ�·��
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/beggar/area/south1.c", 
		"north" : "/d/eastland/beggar/area/west1.c", 
		"south" : "/d/eastland/beggar/area/s4w1.c", 
		"west" : "/d/eastland/beggar/area/s1w2.c" ]) );
	ob->reset();
}