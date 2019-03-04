#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("bodyguard lance","护身长枪");
       add("id",({"lance"}) );
       set_short("护身长枪");
       set_long(
           "一把由上好金属打造的长枪\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
        set( "type","jousting");
	set( "min_damage", 10 );
	set( "max_damage", 23 );
	set( "weight", 150 );
	set( "value", ({ 80, "gold" }) );
}
