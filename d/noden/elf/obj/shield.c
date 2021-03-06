#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven shield", "精灵盾");
        add( "id", ({ "shield" }) );
        set_short( "精灵盾" );
        set_long(
                "这是精灵王用特殊的金属所制成的盾，盾上有著精灵的 \n"
                "的标帜。\n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "light_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":4, "evil":-3 ]) );
        set( "extra_skill",([ "block":5 ]) );              
        set( "weight", 50 );
        set( "value", ({ 105, "gold" }) );
        set( "no_sale", 1);
}
