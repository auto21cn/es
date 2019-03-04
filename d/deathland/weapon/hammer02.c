#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Silver steel Hammer","银钢巨□");
       add("id",({"hammer",}) );
       set_short("银钢巨□");
       set_long(
           "矮人用的银钢巨□\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 33 );
    set("type","blunt");
    set("nosecond",1);
	set( "min_damage", 20 );
	set( "max_damage", 45 );
	set( "weight", 280 );
	set( "value", ({ 300, "gold" }) );

}
