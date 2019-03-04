#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel gauntlets", "钢手套" );
	add( "id", ({ "gauntlets" }) );
	set_short( "钢手套" );
	set_long(
		"这是一双钢制的手套。\n"
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "weight", 50 );
	set( "value", ({ 880, "silver" }) );
}
