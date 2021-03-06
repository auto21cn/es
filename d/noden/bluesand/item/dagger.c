#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long dagger", "长柄匕首" );
	add( "id", ({ "dagger" }) );
   set_short( "长柄匕首" );
	set_long(
		"一把长而锋利的匕首，柄部为了方便挥动而加长。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weapon_class", 11 );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "bleeding", 5 );
	set( "weight", 35 );
	set( "value", ({ 170, "silver" }) );
}
