#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "白色新娘头纱");
        add( "id", ({ "lace" }) );
   set_short( "白色新娘头纱");
        set_long(
		 "这是用纯白的蕾丝做成的美丽头纱，上面还缀著几朵红色的玫瑰。\n"
        );
        set("unit","顶");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
   set( "wedding_obj", 1 );
	set( "no_sale",1);
   set( "value", ({ 2800, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "female") {
        printf(
                  "别开玩笑了, 你想当人妖吗?\n" );
        return 1;
        }
}

