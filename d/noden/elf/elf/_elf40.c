// File: /d/noden/elf/elf/elf40.c
// Generated by Roommaker Mon Dec  4 21:52:57 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�ض�");
	ob->set_long( @LONG_DESCRIPTION
 �˴���һ��ԭʼ�Թ�����ǰ��ħ������ʱ��������������һЩħ��սʿ�����
 �Թ����Ӵ�����ÿ����Բ֮ҹ���Թ������Ǵ������������ĺ��������������
 �Ѵ˴���Ϊ���أ��Ͻ����˽��룬��������ʱ����ݱ䣬�˴��ѱ�����˵���
 ��      
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"east" : "/d/noden/elf/elf/elf38", 
		"west" : "/d/noden/elf/elf/elf40", 
		"north" : "/d/noden/elf/elf/elf43", 
		"south" : "/d/noden/elf/elf/elf36" ]) );
	ob->reset();
}