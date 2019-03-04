#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("white lead ringmail", "白铅环甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "白铅环甲");
        set_long(
                "这是一件由白铅制的环甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal"); 
        set( "armor_class", 28 );
        set( "defense_bonus", 3 );
        set( "weight", 270 );
        set( "value", ({ 150, "gold" }) );
}






