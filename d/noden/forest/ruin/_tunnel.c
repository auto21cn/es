// File: /d/noden/forest/ruin/tunnel.c
// Generated by Roommaker Mon Dec  4 21:29:37 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ͨ��");
	ob->set_long( @LONG_DESCRIPTION
���������ϱ������ͨ��, �������ҵ�ǽ�ھ�����ʯ�����ɵ�, ����
�൱����ΰ׳�ۡ�ͨ��������������������ʯ����, ���Ҹ������в�ͬ��
��������, ����Ϊ�����ߵ���˼��̾���ѡ�
    ͨ�����ϱ��Ǹ�����, ��������һƬ�ڰ���
LONG_DESCRIPTION
	);

	ob->set( "light", 0 );
	ob->set( "exits", ([ 
		"north" : "/d/noden/forest/ruin/tunnel_2", 
		"south" : "/d/noden/forest/ruin/n_hall" ]) );
	ob->set( "item_desc", ([ 
		"statues" : @LONG_TEXT
    ��Щʯ���񶼱�����춱���һ��������İ�Բ��С����, ��ά������
���á����Ǿ�����С����������������, ���õ�������������������̬
������߲��ɵ÷������ĵ�һЦ��
LONG_TEXT
, 
		"statue" : @LONG_TEXT
    ���ʯ���񱻰���춱���һ��������İ�Բ��С����, ��ά�����൱
�á�������С����������������, ���õ�������������������̬�����
�߲��ɵ÷������ĵ�һЦ��
LONG_TEXT
 ]) );
	ob->reset();
}