#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "regular chainmail", "□甲" );
	add( "id", ({ "chain", "mail", "regular" }) );
	set_short( "制式□甲" );
	set_long(
		"这件□甲看起来很重，但是相对地能提供相当不错的保护。\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 15 );
	set( "value", ({ 400, "silver" }) );
}
