// File: /d/eastland/mumar/m_square.c
// Generated by Roommaker Sat Nov 25 13:55:59 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���е������ؽ̳�");
	ob->set_long( @LONG_DESCRIPTION
���߽���һƬ�ܴ�Ĺ㳡���������;��ⲻͬ���ǣ������һƬ���ţ�һ������
��û�У�����������һ֧�붼���ü����ϱ��Ĺ��Ŷ��ǽ��գ����ߵĿⷿ��Ҳ������
�����ġ��ڰ��Ĺ��ڣ�ֻ�����ߵĳ�������һ˿����ɫ�Ĺ���͸����
�̳��ϻ�����
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"west" : "/d/eastland/mumar/m_kitchen", 
		"up" : "/d/eastland/mumar/m_stage" ]) );
	ob->reset();
}