#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "白色新娘鞋");
        add( "id", ({ "boots" }) );
   set_short( "白色新娘鞋" );
        set_long(
		 "这是一双由纯丝制成的白色新娘鞋，看起来十分高雅大方。\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set("material","cloth");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
        set( "weight", 100 );
   set( "value", ({ 3450, "silver" }) );
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
