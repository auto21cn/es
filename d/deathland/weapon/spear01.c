#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("long spear of Wind", "风之长矛");
	add ("id",({ "spear" }) );
	set_short("风之长矛");
	set_long(
            "一把曾在战争中发挥极大功\能的长矛,它能够随著风向刺入敌人的心脏\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 25 );
	set( "type", "thrusting" );
	set( "min_damage", 10 );
	set( "max_damage", 23 );
	set( "weight", 190 );
	set( "value", ({ 2220, "silver" }) );
}

