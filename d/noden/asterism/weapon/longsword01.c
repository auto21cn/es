
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("halfling longsword", "半身人长剑");
        add ("id",({ "sword" }) );
        set_short("半身人长剑");
        set_long(
            "这是半身人守卫所使用的长剑。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 22 );
        set( "type", "longblade" );
        set( "min_damage", 15);
        set( "max_damage", 23 );
        set( "weight", 180 );
        set( "value", ({ 1420, "silver" }) );
}

