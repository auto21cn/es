#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("shoes", "布鞋");
        add( "id", ({ "shoes" }) );
        set_short("布鞋");
        set_long(
                "这双鞋是一针一线密密缝制的。\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set( "material", "cloth");
        set( "armor_class", 5 );
        set( "weight", 50 );
        set( "value", ({ 10, "gold" }) );
}






