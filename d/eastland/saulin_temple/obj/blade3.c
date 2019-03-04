#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastard blade", "精钢戒刀" );
	add( "id", ({ "blade" }) );
	set_short( "精钢戒刀" );
	set_long(
		"这是一把用精钢铸成的超级大戒刀，是少林寺罗汉堂弟子惯用的兵刃。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 178 );
	set( "nosecond", 1 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "value", ({ 600, "silver" }) );
}
