// File: /d/eastland/haiwei/mroad3.c
// Generated by Roommaker Sat Jan 22 02:47:08 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("��ʯ���");
        set_long( @C_LONG_DESCRIPTION
������������һ����ʯ���̳ɵĴ���������Ǻ�����Ĵ�֣�������һ������
�Ĵ������Ա�⿪���̵꣬��ʯ�������������ͨ������������һ����ΰ����¥
��������������š��������֣����ϵ���ʯ���ͨ��һƬ�����͵���Ұ��
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/mroad4", 
                "west" : "/d/eastland/haiwei/shop", 
                "north" : "/d/eastland/haiwei/n_gate", 
                "east" : "/d/eastland/haiwei/mroad2" ]) );
        set( "objects", ([ 
                "vender" : "/obj/vendor" ]) );
        reset();
#include <replace_room.h>
}