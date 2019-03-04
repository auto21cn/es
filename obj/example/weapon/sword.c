#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("long sword", "长剑");
	add ("id", ({ "sword" }) );
	set_short( "a long sword", "长剑");
	set_long(
		"It has a steel blade which is very sharp.\n",
		"这把长剑有十分锋利的剑锋。\n"
	);
	set( "weight", 40 );
	set( "weapon_class", 7 );
	set( "type", "shortblade" );
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set ("value", ({ 12, "gold" }) );
}
