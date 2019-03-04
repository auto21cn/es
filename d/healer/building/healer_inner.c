#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void reset()
{
    "/d/healer/objs/model.c"->apply_load();
    ::reset();
}

void create()
{
	::create();
    set_short("Healer's inner room", "��ҽ���鷿");
	set_long( @C_LONG_DESCRIPTION
��������ҽ���ǽ���ҽ���ĵõĵط���ͬʱҲ����ҽ������ϰ��ĵĳ���, 
�������������Ŀ�ľ��Ƿ��ڷ�������, �����鲻�����ҽ������ϰ��ĵ�ͭ
��ģ��, �����ʾ��һ��ѵľ���������, ��Ϊ�����һ�Ÿ��Ѷȵļ���, ��
�ǲ���׼ȷ������, ����������޷���ص����, ���ϵ��ر��ϸ�Ҫ������, 
һ��Ҫ��ģ������ϰ��������, �ſ��������롣
C_LONG_DESCRIPTION
	);

	set( "light", 1 );

        set( "objects", ([
                       "model" : "/d/healer/objs/model" ,
                       ]) ) ;	
	set( "exits", ([ 
		"west" : "/d/healer/building/healer_guild",
		"up" : "/d/healer/building/healer_upper",
		"south" : "/d/healer/building/healer_troom",
		"north" : "/d/healer/building/healer_reagent" 
		
		]) );

	reset();
}
