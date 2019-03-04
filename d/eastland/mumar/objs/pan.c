#include <mudlib.h>
 
inherit WEAPON;
 
void create()
{
        set_name("pan", "平底锅");
        set_short("平底锅");
        set_long(
                "这是一支厨师用的平底锅。\n"
        );
        set( "unit", "支" );
        set( "weight", 80 );
        set( "type", "blunt" );
        set( "weapon_class",10 );
        set( "min_damage", 6 );
        set( "max_damage", 12 );
        set( "value", ({ 50, "silver" }) );
}
