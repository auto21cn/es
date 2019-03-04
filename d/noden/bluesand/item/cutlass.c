#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "cutlass", "弯刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "弯刀" );
	set_long(
		"一把精致的弯刀，它看起来十分锐利。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 15 );
	set( "min_damage", 10 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 420, "silver" }) );
}
