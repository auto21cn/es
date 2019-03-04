#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "拐杖" );
	add( "id", ({ "stick" }) );
   set_short( "拐杖" );
	set_long(
		"这是一根用坚硬的木头做成的拐杖，目的是让行动不方便\n"
		"的人使用的。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 100 );
	set( "value", ({ 230, "silver" }) );
}
