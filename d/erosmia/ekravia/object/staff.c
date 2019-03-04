#include "../ekravia.h"
inherit WEAPON;

void	create()
{
	set_name("staff", "□杖");
	add( "id", ({ "staff" }) );
	set_short("□杖");
	set_long(
		"一把普通的□杖\n"
	);
	set( "unit", "把" );
	set( "weight", 30 );
	set( "type", "blunt" );
	set( "weapon_class", 10 );
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "value", ({ 50, "silver" }) );
}
