
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven knife", "精灵小刀");
        add ("id",({ "knife"}) );
        set_short( "精灵小刀" );
        set("unit", "把");
        set_long(
            "这是幼小的精灵们用石头做成的玩具小刀。\n"
        );
        set( "weapon_class", 4 );
        set( "type", "dagger" );                        
        set( "min_damage", 2 );
        set( "max_damage", 5 );
        set( "weight", 35 );
        set( "value", ({ 8, "silver" }) );
}
