// File: /d/eastland/haiwei/mroad2.c
// Generated by Roommaker Tue Jan 25 02:51:16 1994

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("��������");
        set_long( @C_LONG_DESCRIPTION
�����������ں�����Ĵ���ϣ�������һ��С���������������һ����ɫ
����������д�����ò�ͤ����������һ�������Ĵ�֣�����������ʯ���������
��ľ����ǰ���������������ٵ�������Ϊ�����ϱ��Ĺٲ����ҹ��ͣ������
�۳�����������ϡ�
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/tea_shop", 
                "west" : "/d/eastland/haiwei/mroad3", 
                "east" : "/d/eastland/haiwei/mroad1" ]) );
        set( "objects", ([ 
                "soothsayer" : "/d/eastland/haiwei/monster/soothsayer" ]) );
        reset();
#include <replace_room.h>
}