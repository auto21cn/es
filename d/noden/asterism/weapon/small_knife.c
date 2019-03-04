
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("little knife","小刀");
        add ("id",({ "knife" }) );
        set_short( "小刀");
        set_long(
            "这是一把小刀。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 5 );
        set( "type", "dagger" );
        set( "min_damage", 3);
        set( "max_damage", 7 );
        set( "weight", 50 );
        set( "value", ({ 64, "silver" }) );
}

