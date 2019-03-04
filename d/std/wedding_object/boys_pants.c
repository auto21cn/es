#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "长裤");
        add( "id", ({ "pants" }) );
        set_short( "a pair of pants", "新郎礼服的长裤");
        set_long(
                "A pair of wedding pants made of silk.\n",
                "这是一件由天山蚕丝织成的长裤。\n"
        );
        set( "unit", "条");
        set( "type", "legs" );
        set( "material","cloth" ) ;
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
        set( "no_sale", 1 );
        set( "value", ({ 60, "gold" }) );
}
