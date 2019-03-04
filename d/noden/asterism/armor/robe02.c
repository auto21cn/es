#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("holy robe", "圣袍");
        add( "id", ({ "robe" }) );
        set_short( "圣袍");
        set_long(
              "这是一件附与地精神圣力量的法袍。整件衣服上闪耀著金色的符号。 \n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 40 );
        set( "defense_bonus", 7 );
        set("special_defense",
              (["fire":30,"cold":30,"evil":30]) );
        set( "weight", 170 );
        set( "value", ({ 270, "gold" }) );
}
