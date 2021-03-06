#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Zeus Amulet","宙斯淡玉护身符" );
        add( "id", ({ "amulet","zeus amulet" }) );
        set_short( "宙斯淡玉护身符" );
        set_long(
                "希腊诸神之首宙斯的护身符，晶莹淡雅的翠玉反而更显出护身"+
                "符的气派\n"
        );
        set( "unit", "个" );
        set("material","scholar");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 2510, "silver" }) );
}
