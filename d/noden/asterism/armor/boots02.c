#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Obsidian boots", "黑曜石长靴");
        add( "id", ({ "boots" }) );
        set_short( "黑曜石长靴");
        set_long(
                "这是一双黑曜石长靴.\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set("material","element") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "weight", 130 );
        set( "value", ({ 70, "gold" }) );
}






