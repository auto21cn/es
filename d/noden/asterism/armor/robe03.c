#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("magic robe", "法袍");
        add( "id", ({ "robe" }) );
        set_short( "法袍");
        set_long(
                "这是一件地精法师惯穿的的法袍。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
        set( "weight", 170 );
        set( "value", ({ 120, "gold" }) );
}
