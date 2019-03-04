#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("javelin", "长戈");
        add ("id",({ "javelin" }) );
        set_short("长戈");
        set_long(
            "一把长戈。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 10 );
        set( "type", "thrusting" );
        set( "min_damage", 5 );
        set( "max_damage", 13 );
        set( "weight", 150 );
        set( "value", ({ 150, "silver" }) );
}
