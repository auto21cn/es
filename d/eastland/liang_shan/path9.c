#include "/d/eastland/liang_shan/takeda.h"
#include <move.h>

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("��ƺ");
        set_long(@Clong
����դ���룬������������һƬ��������Ĳ�ƺ������һ�Ŵ��̵ĵ�̺������
����һ���ʯ����ΪС�����ǳ����š���ƺ���ᣬ�����õĺ������߸߸ߵ�������
����ƺһ������һ��ˮ�ء�
Clong
        );
        set ("c_item_desc",([
                "pool":@pool
һ��СС�ĳ��ӣ���������������ˮ��ֲ�
pool
                        ]));
        set_outside("eastland");
        set("have_iron",1);
        set("exits",([
                "north":TROOM"hall",
                "south":TROOM"gate2",
                        ]) );
        create_door("south","north",([
                "keyword" : ({"iron prism","prism" }),
                "status" : "closed",
                "c_desc" : "һ�����ص���դ",
                "c_name" : "��դ",
                "name":"iron prism",
                "desc":"an iron prism"
                        ]) );
        reset();
}

void init()
{
        add_action("do_search","search");
        add_action("do_take","take");
}

int do_search(string arg)
{
        if ( !arg || arg != "pool") return 0;
        if ( !query("have_iron") )
        {
                write("�����������ˮ���ҵ�ʲ�ᣬ��Ůͼ��??\n");
                return 1;
        }
        write("�㿪ʼ��Ѱ���ˮ�أ���ע�⵽ˮ���еĲݶ�����һ���ٶ�(iron)��"+
                        "Ҳ��\�����\n������(take)����\n");
        return 1;
}

int do_take(string arg)
{
        object iron;
          iron= new("/d/noden/hawk/obj/iron");
        if ( !arg || arg != "iron") return 0;
	if (!query("have_iron") ) return 0;
        write ("������ٶ��Ӳݶ������˳���...\n");
        if( (int)iron->move(this_player()) != MOVE_OK )
                iron->move( this_object() );
        this_player()->set_temp("help_tailor",1);
        delete("have_iron");
        return 1;
}

int clean_up() { return 0; }