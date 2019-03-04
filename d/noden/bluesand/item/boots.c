#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long boots", "长靴" );
	add( "id", ({ "boots" }) );
   set_short( "长靴" );
	set_long( 
		"一双用海豹皮做成的长统靴，看起来品质不错。\n"
	);
	set( "unit", "双" );
	set( "type", "feet" );
    set( "material", "leather");
	set( "armor_class", 6 );
	set( "special_defense",(["cold":3,]) );
	set( "value", ({ 320, "silver" }) );
	set( "weight", 50 );
}
