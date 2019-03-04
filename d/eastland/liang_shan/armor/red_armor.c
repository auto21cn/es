#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("red armor","朱红甲");
    add("id",({"armor"}) );
    set_short( "red armor","朱红甲");
	set_long(
		"This is a red armor for warriors. \n",
		"一件朱红的战甲，看来品质还不错．\n"
	);
	set( "unit", "件" );
	set( "weight", 75 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","light_metal");
	set( "defense_bonus", 3 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":4,"poison":1]));
}
