#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind helmet", "束云头带");
        add( "id", ({ "helmet" }) );
        set_short( "束云头带");
        set_long(@C_LONG
束云头带是由震八方妻子由天然蚕丝编制而成的。是震八方最心爱的头带。
C_LONG
        );
        set("unit","顶");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "weight", 40 );
        set( "value", ({ 200, "gold" }) );
}



