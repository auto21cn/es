
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("longsword", "长剑");
        add ("id",({ "sword", "longsword"}) );
        set_short( "长剑" );
        set_long(
            "它的剑刃看起来十分锋利，应是一把好武器。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 14 );
        set( "type", "longblade" );
        set( "min_damage", 7 );
        set( "max_damage", 16 );
        set( "weight", 75 );
        set( "value", ({ 200, "silver" }) );
}

