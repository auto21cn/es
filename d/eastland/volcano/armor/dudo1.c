#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("red du-do", "红色肚兜");
        add( "id", ({ "du-do" }) );
        set_short( "红色肚兜");
        set_long(
                "这件肚兜是矮灵族小女孩在穿的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "weight", 90 );
        set( "value", ({ 9, "gold" }) );
}






