#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("enforcer's robe", "执事之袍");
        add( "id", ({ "robe" }) );
        set_short("执事之袍");
        set_long(
                "这件长袍是执事常穿著的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 13 );
        set( "weight", 160 );
        set( "value", ({ 40, "gold" }) );
}






