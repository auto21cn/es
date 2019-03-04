
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Silver longsword", "银剑");
        add ("id",({ "sword" }) );
        set_short("银剑");
        set_long(
            "这是银制的剑，自古传言银制品天生带有神圣的力量。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
        set( "type", "longblade" );
        set( "min_damage", 20);
        set( "max_damage", 29 );
        set( "weight", 160 );
        set( "value", ({ 2500, "silver" }) );
}

