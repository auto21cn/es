// File: /d/eastland/beggar/area/s4e2.c
// Generated by Roommaker Tue Jul 30 18:46:06 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��н���塻�㳡");
	ob->set_long( @LONG_DESCRIPTION
����һ��Ƭ��ɰ�㳡,��Ϊ��ؤ����ӳ��ڴ˴����书, ���Ե����Եù�ͺ
ͺ��һ���Ӳ�Ҳû�С���ʱ���εĺܴ�Ю��������Ļҳ�,������ÿ���ϱߵĸ�
ɽ��������ɽ�硻,������۾�����������ǡ�ؤ��ⶨ��һЩˮ�����ֵĹ���
,���Ǵ���ȱ����һ��Ƭ�յؿ��Թ���������ϰ, ����ÿ�������ֲ��Ƥ�Ĺ�����
�����˷���, ��Ǻ����ǻ��ǵü���������ȥ�����ͱ��߶��ǹ㳡�ļ�������,��
����һ��Ƭ���ֶ��ϱ�����ɽ�¡�
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exit_suppress", ({ 
		"southeastup", 
		"seu" }) );
	ob->set( "exits", ([ 
		"seu" : "/d/eastland/legend/lake/mountain0.c", 
		"southeastup" : "/d/eastland/legend/lake/mountain0.c", 
		"north" : "/d/eastland/beggar/area/s1e2.c", 
		"west" : "/d/eastland/beggar/area/s4e1.c" ]) );
	ob->reset();
}