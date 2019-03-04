#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("lucky dagger", "幸运匕首");
	add( "id", ({ "dagger" }) );
	set_short("幸运匕首");
	set_long(
		"这是一把雕著幸运女神的精巧匕首，锋锐的刃上泛的可爱的紫光。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 25 );
	set( "weight", 40 );
	set( "value", ({ 430, "silver" }) );
}
