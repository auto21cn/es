#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("orb ring", "地精水晶戒指");
        add( "id", ({ "ring" }) );
        set_short( "地精水晶戒指");
        set_long(
                "一只水晶戒指。从很久前起，它就是地精长老院首席的信物。\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 10 );
        set( "weight", 15 );
        set("no_sale",1) ;
        set( "value", ({ 1600, "gold" }) );
}



