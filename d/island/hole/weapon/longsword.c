#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Standard Longsword", "制式长剑" );
	add( "id", ({ "longsword","sword","standard" }) );
	set_short( "制式长剑" );
	set_long(
		"这是一把标准的长剑，不论长度或重量都很适合初学者使用。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 25 );
	set( "min_damage", 13 );
	set( "max_damage", 24 );
	set( "value", ({ 470, "silver" }) );
}
