#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("blunt","扁担");
       add("id",({"blunt",}) );
   set_short("扁担");
       set_long(
@C_LONG
    这是奴役用来挑货物的长扁担。
C_LONG
        );

        set( "unit", "把" );
        set( "weapon_class", 9 );
    set("type","blunt");
        set( "min_damage", 6 );
        set( "max_damage", 10 );
        set( "weight", 35 );
        set( "value", ({ 80 , "silver" }) );
}
