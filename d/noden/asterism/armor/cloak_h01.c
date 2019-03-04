#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling magician cape", "半身人魔法师披风");
        add( "id", ({ "cape" }) );
        set_short( "半身人魔法师披风");
        set_long(
                "这是半身人魔法师专用的披风 \n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 155, "gold" }) );
}



