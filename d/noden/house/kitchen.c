// File: /d/noden/house/kitchen.c
// Generated by Roommaker Wed Dec 22 23:04:53 1993

#include <mudlib.h>

inherit ROOM;
int cookie;

void create()
{
	::create();
   set_short("����");
	set_long( @LONG_DESCRIPTION
������Ĳ��ÿ����������ſ��Բ³�������һ�������һЩ�Ͼɲ����ĳ���
(cupboard)�ͳ����þ�ɢ���ڷ����У�ǽ����һ������Ͱ��(can)�ںڰ��з�����
��������չ�ȥ�Ĺ��ߣ��������Իص������ϡ�
LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"cupboard" : @LONG_TEXT
��Щ������Щ�Ѿ������˻ҳ�����Щȴ���õ�һ����Ⱦ������һ������������
������ʳ�����ζ....
LONG_TEXT
, 
		"can" : @LONG_TEXT
����������Ͱ��....��һ������������һ���ƿ����ӣ�һ�ɼ���������Ϣ��
ʬ��ζð�˳����������̽����Ӹǻ�ȥ��
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : "/d/noden/house/pass3" ]) );
	set( "objects", ([ 
		"ham" : "/d/noden/house/monster/ham" ]) );
   set( "search_desc", ([
            "cupboard" :  "@@search_cupboard" ]) );
	reset();
}

void reset()
{
        ::reset();
        cookie = 1;
}

string search_cupboard()
{
        object obj;

   if( !cookie ) return
            "���������ң���û�з����κζ�����\n";
   obj = new( "/d/noden/house/obj/cookie" );
   obj->move( this_object() );
   cookie = 0;
   return "����ϸ��������, ������һƬ��Ǭ��\n";
}