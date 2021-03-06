#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "iron axe", "铁斧" );
	add( "id", ({ "axe" }) );
   set_short( "铁斧" );
	set_long(
		"这把铁斧上面虽然有一点铁锈，但是斧刃部份仍然光滑锋利。\n"
	);
	set( "unit", "把" );
	set( "type", "axe" );
	set( "weapon_class", 11 );
	set( "min_damage", 6 );
	set( "max_damage", 15 );
	set( "nosecond", 1 );
	set( "weight", 120 );
	set( "value", ({ 70, "silver" }) );
}
