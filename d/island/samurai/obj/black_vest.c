#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "black vest","黑色战甲");
        add( "id", ({ "vest" }) );
        set_short( "black vest","黑色战甲" );
        set_long(@AAA
一个黑色的战甲,是用重金属所制成的,所以非常的重,不是普通人可以用的防具
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 24 );
        set( "defense_bonus", 5 );
        set("material","heavy_metal");
        set("special_defense",(["fire":10 ,"evil":10]));
        set( "weight", 270 );
        set( "value", ({ 1200, "silver" }) );
}
