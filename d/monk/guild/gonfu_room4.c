#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("����ȭ�����䷿");
	set_long( @LONG_DESCRIPTION
��һ���ű㿴��һЩ�������ɮ��ȫ��ȫ�������ȭ�����䷿��������˺�ˮ��
ζ����ԭ���˵ر���������ɮѧϰ����ȭ�������䷿������ȭ�����������������ѧ  
������ʱ����ʹ�á���ϸ��˵���뿴����(board)��
������ǰ�м����ǽ��(wall)���������Σ��㲻��������Ŀǰ��ȭ������ѡ���ʵ���
ȭ��ȥ��ϰ(train)�� �����������ֵ��޺��á� 
LONG_DESCRIPTION
	);

set("c_item_desc",([
            "board" : 
"���ֻ���ȭ��\n"
"����ȭ����������ɮ���õ��书\��������ȭ�������㹻��������ڱ���ϰ�÷���\n" 
"������ȭ������Щȭ���ǲ����˹�\����ʹ�õģ�һ����ѧ���ˣ���ս�����㱾����\n"
"������ʹ����Щȭ����ʹ�����ڳ��ֿ�ȭʱҲ����һ����ս��������\n"
"���ֻ���ȭ������Ҫ̫�����ϰ���������Ȳ��䣬������ɮ�˳��õĿ��ַ�������\n"
"��ѧ��һ��ȭ���ᣬ���� \" fist [ȭ������]\" ��ʹ�����������Զ��ں͵��˶�\n"
"սʱʹ�����������ɼ�������ʽ֮ս��ѶϢ��������䱸������ȭ����������á�\n"
"һ����ԣ�ʹ��ȭ����ս����ÿһ�γ�ȭʱ��������������������ã�ȭ����Ȼ��\n"
"û��Ч�����м��мǡ���Щ�͵ȼ�ȭ�������������������ʹ�á�\n"
"ʹ��ָ�� \" fist now \" �����ʾ����Ŀǰ��ʹ�õ�ȭ����\n"
]));
        set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
//		"north" : SAULIN"gonfu_room3",
		"north" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"wall": "view_catalog" ]) );

	set_gonfu_type("fist");
	set_gonfus( ([
		"sh_fist"    : ({ "fist-technic",  1,     0 }),
		"long_fist"  : ({ "fist-technic",  7,   100 }),
		"tb_fist"    : ({ "fist-technic", 17,   200 }),
		"ro_han"     : ({ "fist-technic", 30,   700 }),
		"ho_fist"    : ({ "fist-technic", 42,  1500 }),
		"fu_hu"      : ({ "fist-technic", 53,  4000 }),
        "wei_to"     : ({ "fist-technic", 65,  8000 }),
		"drunk_fist" : ({ "fist-technic", 75, 12000 }),
	]) );

	reset();
}