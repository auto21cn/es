// File: /d/eastland/haiwei/temple.c
// Generated by Roommaker Thu Dec 30 02:04:36 1993

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("�򺣽�����");
        set_long( @C_LONG_DESCRIPTION
��������վ���򺣽������Ĵ���һ�����ɫ�Ĵ����������˸�ʽ�ʻ�
�ع����򺣽����������������ݵ�վ������ǰ�Ĺ����ϣ����ߵ�ʯ���Ͽ���һ��
����(distich)�����ߺ��ϱߵ�Բ�ι���ͨ���������ԵĻ��ȣ����߳����Ĵ���
�Ű��ϻ���������ִ���컭ꪵ����佫��(lieutenant)��������������ǵ�����
����������򺣽����ݰ���\Ը(worship)��˵�������ᱣ���㡣
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "item_desc", ([ 
                "distich" : "����д��:\n      �����˳����̩��\n", 
                "lieutenant" : "�����򺣽��������ܺ���ʱ�ĸ������˳ơ��󽫾����롸�ҽ�������\n" ]) );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/temple_square" ]) );
        reset();
}
void init()
{
	add_action("do_worship","worship");
}
int do_worship()
{
	tell_object(this_player(),
	"��˫�ֺ�ʲ�����򺣽���������ݰݣ�ĬĬ������ ES �����˳��\n"
	"ÿһ�� ES �����Ѷ��Ҹ����� !!\n");
	this_player()->save_me();
        this_player()->set_explore("eastland#17");
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}