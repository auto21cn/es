#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "occult leggings", "神秘胫甲");
        add( "id", ({ "leggings" }) );
        set_short("神秘胫甲");
        set_long(
                "这是用一种神秘的质料所制成的胫甲\n"
        );
        set("unit","双");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 2);
        set( "weight", 50 );
        set( "value", ({ 400, "gold" }) );
}






