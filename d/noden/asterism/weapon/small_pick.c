
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("toy spear", "玩具矛");
        add ("id",({ "spear" }) );
        set_short( "玩具矛");
        set_long(
            "这是一把像玩具的矛。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 3 );
        set( "type", "thrusting" );
        set( "min_damage", 2);
        set( "max_damage", 6 );
        set( "weight", 70 );
        set( "value", ({ 44, "silver" }) );
}

