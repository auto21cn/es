#include "../ekravia.h"
inherit WEAPON;

void	create()
{
	set_name("dagger", "匕首");
	add( "id", ({ "dagger" }) );
	set_short("匕首");
	set_long(
		"一把普通的匕首。\n"
	);
	set( "unit", "把" );
	set( "weight", 30 );
	set( "type", "dagger" );
	set( "weapon_class", 20 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "second", 1 );
	set( "value", ({ 300, "silver" }) );
}
