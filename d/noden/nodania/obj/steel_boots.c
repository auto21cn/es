#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel boots", "钢战靴" );
	add( "id", ({ "boots" }) );
	set_short( "钢战靴" );
	set_long(
		"这是一双钢制的战靴。\n"
	);
	set( "unit", "双" );
	set( "type", "feet" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}
