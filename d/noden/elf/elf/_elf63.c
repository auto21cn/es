// File: /d/noden/elf/elf/elf63.c
// Generated by Roommaker Mon Dec  4 21:58:06 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��ԭ");
	ob->set_long( @LONG_DESCRIPTION
������һ���޼ʵĴ��ԭ���������Ķ�������������м��갫��ľ����
��������������ֲ�ﶼ�Ƿǳ��ʺ�С�����������п��Զ�ܵİ��˸�â�ݼ�
�����ԣ�����ϸ�ɿڵ����ݣ�����С��������á�
LONG_DESCRIPTION
	);

	ob->set_outside( "elfhamlat" );
	ob->set( "exits", ([ 
		"east" : "/d/noden/elf/elf/elf62", 
		"north" : "/d/noden/elf/elf/elf61" ]) );
	ob->set( "objects", ([ 
		"butterfly2" : "/d/noden/elf/monster/butterfly1", 
		"butterfly1" : "/d/noden/elf/monster/butterfly1" ]) );
	ob->reset();
}