// File: /d/noden/drow/r16.c
// Generated by Roommaker Mon Nov 27 14:19:04 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�������");
	ob->set_long( @LONG_DESCRIPTION
�����Ǻ������޴�����ӵ��������ֻ��ܣ����������������һ
λŮ�񣭺��ף������Ǻڰ�����������ӭ��������ʱ������������ϴ峤
�������ҽ��ܺ���Ů����ߵĵط���ͨ�����ϴ峤�������������������
ū��ȴû�н���Ů��ף���Ļ��ᡣ
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"west" : "/d/noden/drow/r15" ]) );
	ob->set( "objects", ([ 
		"m5" : "/d/noden/drow/mob/chief" ]) );
	ob->reset();
}