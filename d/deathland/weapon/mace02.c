#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Mithril Mace","米苏里钉头槌");
        add("id",({"mace",}) );
       set_short("米苏里钉头槌");
       set_long(
         "一把米苏里钉头槌.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 24 );
       set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 180 );
	set( "value", ({ 170, "gold" }) );
}
