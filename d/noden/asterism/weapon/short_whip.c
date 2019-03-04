
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Short whip","短鞭");
        add ("id",({ "whip" }) );
        set_short("短鞭");
        set_long(
            "这是一条驯兽师用的短鞭，因为它是五条鞭子缠在同一个握把，\n"
            "所以打起来特别痛。"
        );
        set( "unit", "条");
        set( "weapon_class", 25 );
        set( "type", "whip" );
        set( "min_damage", 18);
        set( "max_damage", 25 );
        set( "weight", 80 );
        set( "value", ({ 840, "silver" }) );
}

