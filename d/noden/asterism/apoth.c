#include "asterism.h"////#pragma save_binary

//translation done. 2-21-94 what about menu? hmm..  -Elon

#include "asterism.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
    set_short("吉拉药材店");
	set_long(
		 @C_LONG_DESCRIPTION
你现在来到一家新开的药材店，整齐的柜台上排放著许多医疗的用品，绷带
、药水、应有尽有，你看到门口的柜台上钉著一张价目表(menu)，这家药材店
是远风镇吉拉药材店的分店。
C_LONG_DESCRIPTION
	);

        set( "shop_name", "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north" : ASTR"city41" ]) );
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	reset();
	set_inventory( ({
		({ "/obj/bandage", 60, 60 }),
		({ "/d/noden/farwind/items/branz_herb", 50, 50 }),
		({ "/d/noden/farwind/items/plaster", 40, 40 }),
		({ "/d/noden/farwind/items/white_plaster", 30, 30 }),
		({ "/d/noden/farwind/items/mikira_potion", 40, 40 }),
		({ "/d/noden/farwind/items/kira_potion", 30, 30 }),
		({ "/d/noden/farwind/items/makira_potion", 20, 20 }),
                ({ ITEM"tea01",20,20 }) ,
	}) );
}

void reset()
{
   room::reset();
   seller::reset();
   return ;
}
