// File: /d/noden/hawk/path4.c
// Generated by Roommaker Thu Jan  6 10:55:53 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("��ɽ��");
	set_long( @C_LONG_DESCRIPTION
������������ɽ����һ��ƽ�أ�������Ȼ���ƽ�Ϊƽ̹�����ǲ�ľ��Ȼ���ò���
�ܸߣ����������ƶ�Ĺ�ϵ���ϱߵ�ƽ�����м��������õ�С�ݣ�������һ����խ
��ʯ���µ�ͨ��ɽ�¡�
C_LONG_DESCRIPTION
	);

	set_outside( "hawk" );
	set( "exits", ([ 
		"northeast" : "/d/noden/hawk/path3", 
		"south" : "/d/noden/hawk/clearing" ]) );
	reset();
#include <replace_room.h>
}