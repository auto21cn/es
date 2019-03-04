#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Red scarf", "红色围巾");
        add( "id", ({ "scarf"}) );
        set_short("Red scarf", "红色围巾");
        set_long(@AAA
这是一条红色的围巾，是忍者加尔福特爱用的围巾，据说
是娜考璐璐亲手织给他的
AAA
        );
        set( "unit", "条"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set("material","cloth");
        set("special_defense",([ "fire" : 20 ]));
        set( "weight", 20 );
        set( "value",({ 660, "silver" }) );
}
