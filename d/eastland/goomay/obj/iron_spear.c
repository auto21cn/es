
#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("Spear of red steel", "火钢矛");
        add ("id",({ "spear" }) );
        set_short("Spear of red steel", "火钢矛");
        set_long(
            "A special spear which made by red magic steel.\n",
            "这是一把由红色魔法磁铁矿打造而成的长矛，闪动著火焰般\n"+
	    "光芒的矛尖，似乎有与众不同的力量。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 25 );
        set( "type", "thrusting" );
        set( "min_damage", 10 );
	set( "max_damage", 36 );
	set( "weight", 190 );
        set( "value", ({ 1650, "silver" }) );
}
