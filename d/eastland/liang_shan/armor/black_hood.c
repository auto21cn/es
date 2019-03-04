#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("black hood", "皂巾");
        add( "id", ({ "hood","black" }) );
        set_short( "a black hood", "皂巾");
        set_long(
                "A black hood .\n",
                "这是一顶破破烂烂的黑头巾，通常是没什麽身份地位的人穿的 \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 10, "gold" }) );
}



