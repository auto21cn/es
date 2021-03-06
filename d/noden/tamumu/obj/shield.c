#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "tower shield", "塔型盾" );
	add( "id", ({ "shield" }) );
	set_short( "塔型盾" );
	set_long(
	      "这面塔型盾非常沈重，上面还画满了许多奇异的符号。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy_metal" );
	set( "armor_class", 6 );
	set( "weight", 250 );
	set( "special_defense", ([ "fire":2, "energy":-2 ]) );
	set( "value", ({ 500, "silver" }) );
}
