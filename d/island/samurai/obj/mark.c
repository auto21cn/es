#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "chrysanthemum marks", "菊形家徽");
        add( "id", ({ "marks","marks" }) );
        set_short("chrysanthemum marks", "菊形家徽");
        set_long(@AAA
一个菊形家徽,代表著武士队长约修家的家徽
AAA
        );
        set( "unit", "件"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set("material","element");
        set( "weight", 30 );
        set( "special_defense",(["fire":20]));
        set( "value", ({ 800, "silver"
                }) );
        
}
