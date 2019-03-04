#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "scoop", "勺子" );
        add( "id",({ "scoop" }) );
        set_short("勺子");
        set_long(
            "这是把煮饭用的勺子。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 7 );
        set( "type", "blunt" );
        set( "min_damage", 2 );
        set( "max_damage", 8 );
        set( "nosecond", 1);
        set( "weight", 35 );
        set( "value", ({ 200, "sliver" }) );
}
