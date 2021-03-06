#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "巨剑" );
	add( "id", ({ "bastard sword", "sword" }) );
	set_short( "an alloyed bastardsword", "合金巨剑" );
	set_long(
		"You see a bastard sword made of some unknown alloyed metal.\n",
		"这是一把用某种合金铸成的重型剑，剑刃为亮银色泛著红色光泽。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "weapon_class", 29 );
	set( "min_damage", 11 );
	set( "max_damage", 26 );
	set( "value", ({ 750, "silver" }) );
}
