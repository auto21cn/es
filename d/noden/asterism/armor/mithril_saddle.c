#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "米苏里马鞍" );
	add( "id", ({ "saddle" }) );
	set_short( "米苏里马鞍" );
	set_long(
		"这是一副用软米苏里金属制成的马鞍。能提供较舒适的骑乘感觉。\n" );
	set( "type", "saddle" );
        set("material","light_metal");
	set( "armor_class", 10 );
	set( "defense_bouns",2 );
	set( "weight", 120 );
	set( "value", ({ 950, "silver" }) );
}
