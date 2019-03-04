#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wedding suit","白色新娘礼服");
        add("id",({"suit"}) );
   set_short( "白色新娘礼服");
	set_long(
"这是一件白色的新娘礼服，纯白的颜色代表纯洁无暇的爱情。\n"
	);
	set( "unit", "件" );
	set("material","cloth");
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 28 );
	set( "defense_bonus", 5 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3500, "silver" }) );
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
