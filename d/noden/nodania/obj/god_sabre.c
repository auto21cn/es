#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sabre", "佩剑");
	add( "id", ({ "sword" }) );
	set_short("诸神的佩剑");
	set_long(
		"这是诸位大神们随身携带的佩剑。\n"
	);
	set( "unit", "把" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 99 );
	set( "type", "longblade" );
	set( "min_damage", 9 );
	set( "max_damage", 99 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
