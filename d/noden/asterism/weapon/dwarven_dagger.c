
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("dwarven dagger", "矮人匕首");
        add ("id",({ "dagger" }) );
        set_short("矮人匕首");
        set_long(
            "这是一把很锋利的矮人专用匕首,\n"
        );
        set( "unit", "把");
        set( "weapon_class", 24 );
        set( "type", "dagger" );
        set( "min_damage", 18);
        set( "max_damage", 26 );
        set( "weight", 120 );
        set( "value", ({ 1120, "silver" }) );
}
