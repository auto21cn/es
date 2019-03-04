
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("stone long hammer", "石制长槌");
        add ("id",({ "hammer" }) );
        set_short("石制长槌");
        set_long(
            "这是一把石制长槌,它能攻击远方的敌人。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 15);
        set( "max_damage", 26);
        set( "weight", 240 );
        set( "value", ({ 770, "silver" }) );
}

