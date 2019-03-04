#include "../../story.h"
inherit SHOP;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
欢迎来到「巫咸城」最大的一家商店，这家商店是往来游客、商人们以及国民
最常光顾的地方。在商店□你除了可以买(buy)、卖(sell)、估价(value)、或只是
参观(list)以外，老板还愿意「免费」为你鉴定你身上的东西，把你想要鉴定的物
品拿给老板，他就会告诉你物品的正确名称。
C_LONG
	);
	set( "exits", ([ "east" : SCITY"es.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
//	replace_program(SHOP);
}
void init()
{
   ::init();
   write("\n\n商店老板说道：欢迎光临，请问这位客倌要点什麽？\n\n");
}
int can_pass()
{
   write("\n\n商店老板说道：谢谢惠顾，请下次再来。\n\n");
   return 0;
}