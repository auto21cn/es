#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("dark leggings", "黑暗胫甲");
        add( "id", ({ "leggings" }) );
        set_short( "黑暗胫甲");
        set_long(
                "这件胫甲乃是经过地狱之黑暗深渊中炼制而成。\n"
        );
        set("unit","件");
        set( "type", "legs" );
        set( "material", "light_metal");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 200, "gold" }) );
}






