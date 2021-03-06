#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "creset cutlass", "新月弯刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "新月弯刀" );
	set_long(
		"一把长而精致的弯刀，它看起来十分锐利，刀背上刻著十三个新月的刻痕。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 25 );
	set( "min_damage", 8 );
	set( "max_damage", 20 );
	set( "bleeding", 15 );
	set( "weight", 80 );
	set( "value", ({ 1460, "silver" }) );
}
