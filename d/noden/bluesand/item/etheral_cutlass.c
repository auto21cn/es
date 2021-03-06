#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "etheral cutlass", "地狱弯刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "地狱弯刀" );
	set_long(
		"一把闪烁著幽暗光晕的弯刀，拿在手上轻飘飘的，感觉不到重量。\n"
	);
	set( "unit", "把" );
   set( "type", "shortblade" );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 16 );
	set( "weight", 5 );
	set( "value", ({ 320, "silver" }) );
}
