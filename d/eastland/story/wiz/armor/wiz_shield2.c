#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("golden shield","黄金盾");
        add( "id", ({ "shield" }) );
        set_short( "黄金盾");
        set_long(@C_LONG
一面用18K金做成的盾牌，这只有「巫咸国」的人才用的起这样昂贵的盾牌。
C_LONG
        );
        set( "unit","面");
        set( "type", "shield" );
        set( "material","heavy_metal");
        set( "armor_class",7 );
        set( "defense_bonus", 4 );
        set( "weight", 150 );
        set( "value", ({ 2000, "silver" }) );
}



