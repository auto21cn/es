#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black leggings", "黑色护膝" );
	add( "id", ({ "leggings" }) );
	set_short( "黑色护膝" );
	set_long(
		"这是一个黑色的的护膝，看不出是用什麽做成的。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "light_metal" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}
