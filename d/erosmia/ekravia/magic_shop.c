#include "ekravia.h"
inherit SELLER;
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("魔法屋");
	set_long(@Long
这是一间充满神秘气氛的小屋, 一片阴暗中仅有柜台前的一角偶而漏
进一点阳光。柜台後面似乎没人看著, 让人有点不知所措。还好柜台上面
放著一张清单 (list)。
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"south"		: HERE"tinker_way2",
		]) );
	set_inventory( ({ 
		({ "/d/noden/moyada/obj/wands/flamming_wand", 5, 5 }),
		({ OBJ"firework", 5, 5 }),
		({ OBJ"chain_fw", 2, 1 }),
		}) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
你看到一张泛黄的纸张, 上面写著:
LIST
	);
	::show_menu();
}
