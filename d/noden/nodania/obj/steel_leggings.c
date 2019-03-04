#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel leggings", "钢护膝" );
	add( "id", ({ "leggings" }) );
	set_short( "钢护膝" );
	set_long(
		"这是一个钢制的护膝。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 100 );
	set( "value", ({ 1520, "silver" }) );
}
