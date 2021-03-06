#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel glaive", "青钢大刀" );
	add( "id", ({ "glaive" }) );
	set_short( "a highsteel glaive", "青钢大刀" );
	set_long(
		"You see a huge, heavy highsteel glaive. This is the regular\n"
		"weapon of soldiers guarding the Mumar Keep.\n",
		"这是一把巨大、沈重的青钢大刀，戍守边疆的士兵的制式武器。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 28 );
	set( "min_damage", 16 );
	set( "max_damage", 25 );
	set( "weight", 90 );
	set( "value", ({ 430, "silver" }) );
}
