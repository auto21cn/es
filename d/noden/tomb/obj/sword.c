#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "rusty longsword", "锈剑" );
	add( "id", ({ "longsword", "sword" }) );
  set_short( "生锈长剑" );
	set_long(
		"这把长剑已经生满了锈，不过看起来似乎还能当作武器。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 9 );
	set( "min_damage", 5 );
	set( "max_damage", 13 );
	set( "value", ({ 105, "silver" }) );
}
