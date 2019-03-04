#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling ringmail", "半身人环甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short("半身人环甲");
        set_long(
                "这是半身人守卫所专用的环甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 25 );
        set( "defense_bonus", 2 );
        set( "weight", 250 );
        set( "value", ({ 200, "gold" }) );
}






