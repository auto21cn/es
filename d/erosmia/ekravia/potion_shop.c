#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("小药店");
	set_long(@Long
你走进一家小药店。昏暗的小空间里, 各种药材的气味在空中飘汤著
。一个个盛著不知名药物的小瓶子互相推挤著塞满了整个柜台, 几个空烧
杯与酒精灯在小桌上的一角建立了自己的势力范围。
    好不容易你在柜台的一角, 几个药瓶的空隙间找到了你所需要的药品
清单 (list)。
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way3",
		]) );
	set("objects", ([
		"alchemist"	: MOB"alchemist",
		]) );
	set_inventory( ({ 
		({ OBJ"potions/inca_potion", 50, 50 }),
		({ OBJ"potions/green_potion", 30, 30 }),
		({ OBJ"potions/vigor_potion", 30, 30 }),
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
