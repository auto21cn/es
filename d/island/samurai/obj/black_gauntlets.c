#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "black gauntlets","黑色护手");
        add( "id", ({ "gauntlets" }) );
        set_short("black gauntlets","黑色护手" );
        set_long(@AAA
一个黑色的护手,是用重金属所制成的,所以非常的重,不是普通人可以用的防具
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","heavy_metal");
        set( "weight", 100 );
        set( "value", ({ 650, "silver" }) );
}
