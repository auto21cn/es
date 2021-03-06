#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "spear", "长矛" );
	set_short( "a hunting spear", "狩猎用长矛" );
	set_long(
		"A long spear designed for hunting boars.\n",
		"一把用来猎杀野猪用的长矛。\n"
	);
	set( "weapon_class", 6 );
	set( "type", "thrusting" );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "weight", 40 );
	set( "value", ({ 15, "gold" }) );
}
