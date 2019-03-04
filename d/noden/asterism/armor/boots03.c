#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("platinum boots", "白金靴");
        add( "id", ({ "boots" }) );
        set_short( "白金靴");
        set_long(
                "这是一双白金和米苏里金属合金铸成的靴子.\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set("material","heavy_metal") ;
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "weight", 120 );
        set( "value", ({ 250, "gold" }) );
}






