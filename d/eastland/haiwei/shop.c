// File: /d/eastland/haiwei/shop.c
// Generated by Roommaker Fri Jan 21 02:37:34 1994

#include <mudlib.h>

inherit SHOP;

void create()
{
        ::create();
        set_short("��������");
        set_long( @C_LONG_DESCRIPTION
����������һ��װ�ε�������ۼ���̵꣬���������������Ĺ�̨�͵񹤾�ϸ
��̴ľ���Σ�������������һ�Ű���Ƥ�����Ϲ���һ����ҡ���ͥ���С����ڴ���
����һ���������һ������������������ֵĳ��ڡ�
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "exits", ([ 
                "east" : "/d/eastland/haiwei/mroad3" ]) );
        set( "objects", ([
                "trashcan" : "/obj/trashcan" ]) );
        reset();
}