// File: /d/eastland/mumar/wall04.c
// Generated by Roommaker Sat Nov 25 13:51:32 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("�����س�ǽ");
	ob->set_long( @LONG_DESCRIPTION
���ߵ��������صı���ĳ�ǽ�ϣ�����������Ҳֻ�����������һ������гǶ�
�������˺۵ĳǶ��ƺ�����˵��ս���Ĳпᡣ����Ļ�ɫ�羰˿��û���������е�ֻ
��һƬ���š������������̶ӻ������ƶ�������ƬɳĮ��Ψһ�ĵ�׺��
LONG_DESCRIPTION
	);

	ob->set_outside( "eastland" );
	ob->set( "exits", ([ 
		"east" : "/d/eastland/mumar/wall05", 
		"south" : "/d/eastland/mumar/wall03" ]) );
	ob->reset();
}