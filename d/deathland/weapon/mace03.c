#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("little mace","小巧的钉头槌");
        add("id",({"mace",}) );
       set_short("小巧的钉头槌");
       set_long(
         "一把小巧的钉头槌.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 20 );
       set("type","blunt");
	set( "min_damage", 14 );
	set( "max_damage", 26 );
	set( "weight", 110 );
	set( "value", ({ 160, "gold" }) );
}
