// File: /d/noden/tamumu/cave5.c
// Generated by Roommaker Mon Dec  4 19:43:16 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("ʯ��");
	ob->set_long( @LONG_DESCRIPTION
������һ�䲻��̫�����ʯ��֮�У�һЩʯ�Ƶ�����Ʒ����¨(basket)����
��Ψһ�İ��裬�ϱߵ�һ������������س�����һ��....����ͷ(skulls)������
�����������ڵĵط������Ǻܰ�ȫ�����С��һ�㣬�����Ϊ���ǵ�һ���ӡ�
LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"north" : "/d/noden/tamumu/altar" ]) );
	ob->set( "item_desc", ([ 
		"skulls" : @LONG_TEXT
��....������ʮ����ɭɭ������ͷ����һ����Щ����ͷ���滹�õ��ӿ���
����(numbers)����֪����ʲ����˼��
LONG_TEXT
, 
		"basket" : @LONG_TEXT
��Щ��¨��С��һ���е���Բ�ģ��е��Ƿ��ģ��еı��ỹ������������
��������������֪������װ��Щʲ�ᶫ����
LONG_TEXT
, 
		"numbers" : @LONG_TEXT
һ��������......��ʮ������ʮ�ģ��ܹ���ʮ�ĸ�����ͷ�������ʾ����һ
����ʮ�ĵ����֡�
LONG_TEXT
 ]) );
	ob->reset();
}