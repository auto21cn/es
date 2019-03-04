#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "拐杖" );
	add( "id", ({ "stick" }) );
   set_short( "木质拐杖" );
	set_long(
		"这是一根用坚硬的木头做成的拐杖。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 8 );
	set( "min_damage", 4 );
	set( "max_damage", 8 );
	set( "weight", 60 );
	set( "value", ({ 130, "silver" }) );
}
