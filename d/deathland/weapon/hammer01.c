#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Mithril Hammer","巨□");
       add("id",({"hammer",}) );
       set_short("米苏里巨□");
       set_long(
           "矮人用的米苏里巨□\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
    set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 230 );
	set( "value", ({ 100, "gold" }) );

}
