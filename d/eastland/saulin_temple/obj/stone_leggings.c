#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone leggings", "巨石护膝");
        add( "id", ({ "leggings" }) );
        set_short("巨石护膝");
        set_long(
              "这是野蛮人战士专用的护膝，它非常的重，但可以严密的保护你的脚部\n"
        );
        set( "unit", "副");
        set( "type", "legs" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":4, "cold":-3, "divine":-1 ]) );
                       
        set( "weight", 130 );
        set( "value", ({ 90, "gold" }) );
}
