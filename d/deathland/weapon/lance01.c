#include "../echobomber.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
	set_name("Lance of Molader", "莫拉德长枪");
	add ("id",({ "lance" }) );
	set_short("莫拉德长枪");
	set_long(
            "一把末由莫拉德皇室的守卫专用的长枪\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 25 );
	set( "type", "thrusting" );
	set( "min_damage", 10 );
	set( "max_damage", 36 );
	set( "weight", 190 );
	set( "value", ({ 2150, "silver" }) );
}

