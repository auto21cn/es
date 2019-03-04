
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult dagger", "神秘匕首" );
        add( "id",({ "dagger" }) );
        set_short( "神秘匕首" );
        set_long(
            "神秘匕首。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 25 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 150 );
        set( "value", ({ 120, "gold" }) );
}

