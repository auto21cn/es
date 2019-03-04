#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Shinning amulet", "闪闪发光的护身符");
        add( "id", ({ "amulet" }) );
        set_short( "闪闪发光的护身符");
        set_long(
                " 一个闪闪发光的护身符\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set("material","cloth") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 15 );
        set( "value", ({ 122, "gold" }) );
}



