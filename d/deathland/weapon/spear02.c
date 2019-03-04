#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("standard spear", "标准长矛");
	add ("id",({ "spear" }) );
	set_short("标准长矛");
	set_long(
            "一把标准的长矛\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 15 );
	set( "type", "thrusting" );
	set( "min_damage", 7 );
	set( "max_damage", 20 );
	set( "weight", 170 );
	set( "value", ({ 550, "silver" }) );
}

