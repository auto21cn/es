#include <mudlib.h>
#include "/d/thief/thief.h"
inherit SELLER;
inherit ROOM;
void create()
{

	::create();
	set_short("赃物销售中心");
	set_long( @C_LONG_DESCRIPTION
你现在来到了小偷公会内部所附设的销赃中心，帮助小偷处理赃物, 并且提供
公会成员一些方便的道具。你可以看看墙上的价目表(menu), 看看这边卖些什
麽东西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/thief/hall/thief_guild" ,
		"west" : "/d/thief/hall/thief_storage" ,
	]) );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set_inventory( ({
		({ THIEF"hall/weapons/black_dagger", 5, 5 }),
		({ THIEF"hall/armors/cloth", 8, 8 }),
		({ THIEF"hall/misc/bag",3,3 }),
		({ THIEF"hall/misc/knife",3,3 }),
		({ THIEF"hall/misc/pushpin",30,30}),
		({ THIEF"hall/misc/bottle",10,10 }),
		({ THIEF"hall/misc/tape",40,40}),
	}) );
	seller::reset();
}
reset()
{
	room::reset();
	seller::reset();
}

