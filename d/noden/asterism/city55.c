// File: /d/noden/asterism/city55.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���д�·");
	set_long( 
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ�(asterism)�ǵĴ��·,��춰��������ɵ������ݼ����˵�
��������,����ĵ�·ʮ�ֿ�����ֱ,���ҵ�·������ֲ����ľ�������໥����֮��,
���˺��������һ�������Ĺ�԰���ڶ�����һ������(tower) ,��������һ��������
�����˵�����.�����Ǻܼ�̵ĳ�ǽ,����������ķ紵��ɹ,��Ȼ������ҡ��
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set("c_item_desc",([
	    "tower":"һ�������ĺܺ�ΰ�ĸ���.\n"
	    ]) );
	set( "exits", ([ 
		"south" : ASTR"city56",
		"north" : ASTR"city54",
		]) );
	reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str||str!="tower") return 0;
    write("�����������.\n");
    this_player()->move_player(ASTR"tower1-1",
               "%s����������.\n","%s���������.\n");
     return 1;
}