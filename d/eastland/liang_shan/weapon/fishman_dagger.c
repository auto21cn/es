#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("fishman's shortblade", "渔师短刀");
	add("id",({"shortblade"}));
	set_short("渔师短刀");
	set_long(
		"这是一把锋利的短刀，渔夫多用它来防身或处理鱼获。\n"
	);
	set( "unit", "把" );
	set( "weight", 95 );
	set( "type", "shortblade" );
	set( "second",1);
	set( "weapon_class", 17 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "value", ({ 415, "silver" }) );
}
