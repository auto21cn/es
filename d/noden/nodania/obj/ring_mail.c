#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring mail", "环甲" );
	add( "id", ({ "mail", "ring" }) );
	set_short( "环甲" );
	set_long(
		"这是一件环甲，用成千上万个金属环接合而成。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 10 );
	set( "weight", 110 );
	set( "value", ({ 140, "silver" }) );
}
