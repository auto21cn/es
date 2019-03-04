#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril black boots", "米苏里黑鞋");
        add( "id", ({ "boots" }) );
        set_short("a pair of mithril black boots", "米苏里黑鞋");
        set_long(
                "A pair of boots made of mithril and iron  .\n",
                "一双由米苏里金属和铁混合而成的鞋子\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "weight", 80 );
        set( "value", ({ 770, "silver" }) );
}
