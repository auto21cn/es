#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel club", "浑铁棒");
        add ("id",({ "club"}) );
        set_short("浑铁棒");
        set("unit", "把");
        set_long(@C_LONG
这是一把由浑铁所铸造的棒子，看起来不轻的样子。
C_LONG
        );
        set( "weapon_class", 16);
        set( "type", "bo");                        
        set( "min_damage", 10);
        set( "max_damage", 18);
        set( "weight", 160);
        set( "value", ({ 380, "silver" }) );
}
