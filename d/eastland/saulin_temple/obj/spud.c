#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "spud", "小锄头");
        add ("id",({ "spud"}) );
        set_short("小锄头");
        set("unit", "把");
        set_long(
            "这是一把用来整地的小锄头。\n"
        );
        set( "weapon_class", 6 );
        set( "type", "blunt" );                        
        set( "min_damage", 5);
        set( "max_damage", 10);
        set( "weight", 65 );
        set( "value", ({ 80, "silver" }) );
}
