// File: /d/deathland/village/vr6.c
// Generated by Roommaker Thu Nov 23 21:14:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("����������");
	ob->set_long( @LONG_DESCRIPTION
���������ܶ����˵İ���ʿ����սʿ,�����ҩˮζ����������Ǻ��ζ��.�������
�豸�ƺ�ʮ����ȫ,������Ĵ��ҽ��֮��,���˵�ʿ��Ӧ�úܿ���ܻص�ս����.
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/d/deathland/village/v25" ]) );
	ob->set( "objects", ([ 
		"doctor" : "/d/deathland/monster/doctor", 
		"soldier#3" : "/d/deathland/monster/soldier05", 
		"soldier#2" : "/d/deathland/monster/soldier05", 
		"soldier#1" : "/d/deathland/monster/soldier05" ]) );
	ob->reset();
}