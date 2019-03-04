#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name( "orb shield", "冰晶盾" );
        add( "id", ({ "shield" }) );
        set_short( "冰晶盾" );
        set_long(@C_LONG
一块亮晶晶的盾牌。 这是陆阿巧六年前在路上拾获的一块千年冰晶研制而成的。当
初为了能炼化这块冰晶,陆阿巧整整费了七天七夜,再经过三、三,三十六个昼夜才顺
利制成的,可谓心血浩大。
C_LONG        
        );
        set("unit","块");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 7 );
        set( "defense_bonus", 7 );
        set( "weight", 100 );
        set( "value", ({ 4000, "silver" }) );
        set( "light",1);   
}

