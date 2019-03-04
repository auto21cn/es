#include "../farwind.h"

inherit ARMOR;

void create()
{
	set_name( "breast plate", "胸甲" );
	add( "id", ({ "plate" }) );
	set_short( "胸甲");
	set_long(
		"这是一副铁制的胸甲，用来保护胸部及腹部的防具。\n"
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 20 );
	set( "defense_bonus", 0 );
	set( "value", ({ 67, "gold" }) );
}
