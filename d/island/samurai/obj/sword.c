
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja blade", "忍刀" );
        add( "id",({ "blade","sword" }) );
        set_short( "Ninja blade", "忍刀" );
        set_long(
            " 这是一把锋利的长剑，是武士团的制式武器\n"
        );
        set( "unit", "把");
        set( "weapon_class", 22 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}



