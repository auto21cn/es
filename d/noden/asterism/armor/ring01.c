#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("large whitegolden ring", "白金戒指");
        add( "id", ({ "ring" }) );
        set_short( "白金戒指");
        set_long(
                " 一个闪闪发光的大型白金戒指\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","light_metal");
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set( "weight", 25 );
        set( "value", ({ 78, "gold" }) );
}



