#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("square shield","矩方盾");
        add("id",({"shield"}) );
        set_short("矩方盾");
        set_long(
"这是一面方形的盾，上面画满了火龙的图形。\n"
        );
        set( "unit", "面" );
        set( "weight", 150 );
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "value", ({ 1500 , "silver" }) );
}
