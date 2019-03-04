#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Black Mace","黑色钉头□");
        add("id",({"mace",}) );
       set_short("黑色钉头□");
       set_long(
         "由米苏理和银混合制成的黑色钉头□.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
    set("type","blunt");
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 180 );
	set( "value", ({ 400, "gold" }) );
}
