#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("mithril boots", "米苏里战靴");
        add( "id", ({ "boots" }) );
        set_short( "米苏里战靴");
        set_long(
                "一双由米苏里金属造成的战靴.\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set("material","light_metal") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 145, "gold" }) );
}






