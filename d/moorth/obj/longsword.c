#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "longsword", "长剑" );
	add( "id", ({ "long sword", "sword" }) );
	set_short( "an alloyed longsword", "合金长剑" );
	set_long(
		"You see a long sword made of some unknown alloyed metal.\n",
		"这是一把用某种合金铸成的长剑，剑刃为亮银色泛著红色光泽。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 19 );
	set( "value", ({ 470, "silver" }) );
}
