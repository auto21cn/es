#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("obsidian platemail", "黑曜石铠胄");
        add( "id", ({ "platemail" }) );
        set_short( "黑曜石铠胄");
        set_long(
                "这是一件由黑曜石制的铠胄。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","element");
        set( "armor_class", 35 );
        set( "defense_bonus", 5 );
        set( "weight", 330 );
        set( "value", ({ 270, "gold" }) );
}






