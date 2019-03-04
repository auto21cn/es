
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Obsidian longsword", "黑曜石长剑");
        add ("id",({ "longsword" }) );
        set_short( "黑曜石长剑" );
        set_long(
            "这是一把巨大的长剑,以珍贵的矿石,黑曜石所制成的。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 28 );
        set( "max_damage", 39 );
        set( "weight", 240 );
        set( "value", ({ 4444, "silver" }) );
}

