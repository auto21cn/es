
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name("golden battleaxe", "黄金战斧");
        add ("id",({ "axe", "battleaxe" }) );
        set_short( "黄金战斧" );
        set_long(
            "这是一把闪亮的黄金战斧，它巨大斧刃显示出这是把罕见的强力武器。\n"
        );
        set("nosecond", 1);
        set("unit", "把");
        set( "weapon_class", 33 );
        set( "type", "axe" );
        set( "min_damage", 20 );
        set( "max_damage", 45 );
        set( "weight", 300);
        set( "value", ({ 300, "gold" }) );
}

