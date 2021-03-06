#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("purple platemail","紫绣团胸战甲");
    add("id",({"plate","platemail"}) );
    set_short( "purple platemail","紫绣团胸战甲");
	set_long(
		"This is a platemail with beautiful marks....\n",
		"这是一件美丽的战甲，胸前绣满了美丽的图案，令人心旷神怡，你觉\n"
		"得拥有它的人必定是个很有品味的人．\n"
	);
	set( "unit", "件" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 153, "gold" }) );
}
