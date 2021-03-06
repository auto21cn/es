#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("white armor","白甲");
    add("id",({"armor"}) );
    set_short( "white armor","白甲");
	set_long(
		"This is a white armor for warriors. \n",
		"一件雪白的战甲，看来品质还不错．\n"
	);
	set( "unit", "件" );
	set( "weight", 80 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","light_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":3,"poison":1]));
}
