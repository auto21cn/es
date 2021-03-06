// File: /d/noden/farwind/wedding_store.c////#pragma save_binary

#include <mudlib.h>
#include <money.h>

inherit "/std/room/room";
inherit "/std/seller";

void create()
{
	::create();
	set_short("结婚礼服店");
	set_long( @LONG_DESCRIPTION
这里是闻名世界, 别无分号的婚纱礼服店,
你看到四周的橱窗布满一件件精美的礼服, 另外
它也提供捧花及结婚戒指. 你心里想: 还是问问
老板的意见吧!
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/noden/farwind/ebazz" ]) );
   set( "item_func", ([
		"menu" : "show_list",
        ]) );
   set_inventory( ({
         ({ "/d/noden/farwind/wedding_obj/boys_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_pants", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_scarf", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/swallowtail", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_cape", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_lace", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_skirt", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_suit", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_flower", 5, 5 }),
     }) );
   set( "objects", ([
        "boss" : "/d/noden/farwind/monster/meph"
     ]) );
	reset();
}

int show_list()
{
   show_menu();
   write("  结婚戒指 (wedding ring)          5000 银币        无限供应\n"
	 "  结婚护盾圆球 (wedding globe)     8000 银币        无限供应\n");
   return 1;
}

void reset()
{
     room::reset() ;
     seller::reset() ;
   return ;
}
