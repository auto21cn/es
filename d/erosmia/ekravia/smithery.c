#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("铁匠铺");
	set_long(@Long
你走进铁匠铺, 敲敲打打的声音简直是震耳欲聋。声音的来源来自房
间一角的铁砧。热得不得了的鼓风炉在铁砧旁不远处。房间的其他地方散
乱放著一些工具。
    墙上挂著几把武器, 大概都是这里的产品。武器下方放著一些铠甲,
铠甲旁边钉著一个木牌(sign)
Long
);

	set("item_func", ([
		"sign"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way4",
		]) );

	set_inventory( ({ 
		({ OBJ"longsword", 5, 5 }),
		({ OBJ"dagger", 3, 3 }),
		({ OBJ"chainmail", 5, 5 }),
		}) );
		
	set("objects", ([
		"smith"	: MOB"smith",
		]) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
你看到一块粗糙的木牌, 上面刻著:
LIST
	);
	::show_menu();
}
