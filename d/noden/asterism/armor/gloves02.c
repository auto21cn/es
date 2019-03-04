#include "../asterism.h"

inherit ARMOR;

void create()
{
        set_name("white leather gloves", "白色皮革手套");
        add( "id", ({ "gloves" }) );
        set_short( "白色皮革手套");
        set_long(
                "这是一双由皮革制的白手套。\n"
        );
        set("unit","双");
        set( "type", "hands" );
        set("material","leather") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 70, "gold" }) );
}






