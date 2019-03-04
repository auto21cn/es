#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Orb amulet", "水晶护身符");
        add( "id", ({ "amulet" }) );
        set_short( "水晶护身符");
        set_long(
                "一个水晶护身符,水晶自古就含有极强魔力,经过地精神圣\n"
                "力量洗礼的水晶更是其中的极品。\n"
               );
        set("unit","个");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 10 );
        set( "weight", 5 );
        set( "value", ({ 100, "gold" }) );
}



