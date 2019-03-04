#include <mudlib.h>

inherit ROOM;

void create()
{

	::create();
	set_short("小房间");
	set_long( @C_LONG_DESCRIPTION
你来到了冒险工具专卖店旁的一个小房间，地面上满是被裁切过的毛皮碎片。
房间的中间放著一张工作台，桌上放著一些未完成的防具或衣服，一个女裁缝
师坐在桌边，正在努力的工作。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "objects", ([
	             "woman" : "/d/adventurer/hall/monsters/woman"
	                                         ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_shop",
	                                         ]) );
        reset();       
}

