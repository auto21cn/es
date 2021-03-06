#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("Healer's inner room", "行医者书房");
	set_long( @C_LONG_DESCRIPTION
这里是行医者们交换医术心得的地方，不少行医者都以能够将自己的著述陈列
在这里为荣，你在这里可以研读(study)其他行医者所留下来的医学著述，在你的
前方是一个巨大的乌檀木书架，你可以先从书架上的目录(catalog)找起，另外，
你还可以看到一个木制的人体模型(model)，上面标示著一大堆经脉与术语。
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

