#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "米苏里马鞍" );
	add( "id", ({ "saddle" }) );
	set_short(  "米苏里马鞍" );
	set_long(
		"这是一副米苏里制马鞍，骑士们都会为自己的爱马选择舒适的马鞍。\n" 
		);
	set( "type", "saddle" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "weight", 110 );
	set( "value", ({ 430, "silver" }) );
}
