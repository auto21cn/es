// File: /d/noden/tomb/tomb1.c
// Generated by Roommaker Sun Dec 19 23:26:37 1993

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("����ʯѨ");
	set_long( @LONG_DESCRIPTION
����������һ����խ�ĵ���ʯѨ�����ܵ�ǽ������һЩʯש���ɵģ����ϲ���
�ҳ���������һ���֩��������ĵ����и�������������һ��ĹѨ���������ڿ���
�Ѿ���һ��Ⱥ֩���ռΪ��Ѩ�ˡ�
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : "/d/noden/tomb/tomb2", 
		"up" : "/d/noden/13,8.noden" ]) );
	set( "objects", ([ 
		"spider#1" : "/d/noden/tomb/monster/huge_spider", 
		"spider#2" : "/d/noden/tomb/monster/huge_spider" ]) );
	reset();
#include <replace_room.h>
}
