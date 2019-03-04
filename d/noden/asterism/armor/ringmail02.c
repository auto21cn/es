#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("bronze ringmail", "青铜环甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "青铜环甲");
        set_long(
                "这是一件青铜制的环甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 26 );
        set( "defense_bonus", 0 );
        set( "weight", 300 );
        set( "value", ({ 210, "gold" }) );
}






