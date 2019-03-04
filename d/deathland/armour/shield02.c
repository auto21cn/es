#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name( "mithril shield", "米苏里盾牌");
        add( "id", ({ "shield" }) );
        set_short("an mithril shield", "米苏里盾牌");
        set_long(
                "mithril shield of protection .\n",
           "这是用米苏里金属所制成的盾，盾上有著矮人军的标帜--两把交叉的巨□ \n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 152, "gold" }) );
}






