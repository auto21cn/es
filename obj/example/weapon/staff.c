#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "staff", "木杖" );
	set_short( "a wooden staff", "木杖" );
	set_long(
		"A long hard wooden staff.\n",
		"一根长、硬、用来当作武器的木杖。\n"
	);
	set( "weapon_class", 7 );
	set( "type", "blunt" );
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 30 );
	set( "value", ({ 10, "gold" }) );
}
