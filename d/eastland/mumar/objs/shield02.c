#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("round shield","规圆盾");
        add("id",({"shield"}) );
        set_short("规圆盾");
        set_long(
"这是一面圆形的盾，上面是一圈一圈让你看了发晕的圆。\n"
        );
        set( "unit", "面" );
        set( "weight", 150 );
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "value", ({ 1500 , "silver" }) );
}
