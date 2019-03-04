//#pragma save_binary

#include "../dony.h"
inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
欢迎来到『薪胆村』最大也是唯一的商店,这家商店是人们最常光顾的商店之
一。虽然这里普遍贫穷,可是人们还是很乐意掏腰包买一些日常生活用品。在商店
□你除了可以买(buy)、卖(sell)、估价(value)、或只是参观(list)以外,老板还
愿意「免费」为你鉴定你身上的东西,把你想要鉴定的物品拿给老板, 他就会告诉
你物品的正确名称。
C_LONG
	);
	set( "exits", ([ "out" : DBEGGAR"east3.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
	replace_program(SHOP);
}
