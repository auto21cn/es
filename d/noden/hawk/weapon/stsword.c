#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty large sword", "燧石巨剑" );
	add( "id", ({ "sword" }) );
	set_short( "燧石巨剑" );
	set_long(
		"这是一把用暗红色燧石做成的的巨剑，若非具有天赋神力
的人是拿不动的。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 28 );
	set( "value", ({ 950, "silver" }) );
}


