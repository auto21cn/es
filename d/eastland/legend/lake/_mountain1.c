// File: /d/eastland/legend/lake/mountain1.c
// Generated by Roommaker Thu Mar 21 17:29:40 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ɽ��");
	ob->set_long( @LONG_DESCRIPTION
������������һ�����Ӷ��ϵ�ɽ·�����ܶ��Ǿ��׵ĸ�ɽ������ɽ·��������
����խ�������¶Ⱥܶ��������ֿ�Ҫ���µ��ĸо���ɽ·�ĵ��Ϲ�ͺͺ����һ����
��Ҳû�У����Ի��м���޴����ʯ��    
LONG_DESCRIPTION
	);

	ob->set_outside( "noden" );
	ob->set( "exits", ([ 
		"down" : "/d/eastland/legend/lake/mountain0", 
		"up" : "/d/eastland/legend/lake/mountain2" ]) );
	ob->set( "objects", ([ 
		"tiger#2" : "/d/eastland/legend/monster/tiger", 
		"tiger#1" : "/d/eastland/legend/monster/tiger" ]) );
	ob->reset();
}