#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind ring","束云戒指");
        add( "id", ({ "ring" }) );
        set_short( "束云戒指");
        set_long(@C_LONG
束云戒指是震八方和他妻子的定情之物,据说,震八方在这戒指附上一些内劲。
C_LONG
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 3 );
        set( "weight", 10 );
        set( "value", ({ 147, "gold" }) );
}



