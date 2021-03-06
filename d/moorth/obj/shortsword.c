#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "shortsword", "短剑" );
	add( "id", ({ "short sword", "sword" }) );
	set_short( "an alloyed shortsword", "合金短剑" );
	set_long(
		"You see a short sword made of some unknown alloyed metal.\n",
		"这是一把用某种合金铸成的短剑，剑刃为亮银色泛著红色光泽。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 6 );
	set( "max_damage", 13 );
	set( "value", ({ 290, "silver" }) );
}
