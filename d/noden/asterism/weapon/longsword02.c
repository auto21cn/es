
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Brone longsword", "青铜长剑");
        add ("id",({ "sword" }) );
        set_short("青铜长剑");
        set_long(
            "这是青铜制的锋利长剑。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 23 );
        set( "type", "longblade" );
        set( "min_damage", 17);
        set( "max_damage", 25 );
        set( "weight", 190 );
        set( "value", ({ 1720, "silver" }) );
}

