#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("Mithril Axe","巨斧");
       add("id",({"axe",}) );
       set_short("米苏里巨斧");
       set_long(
           "矮人用的米苏里巨斧\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 27 );
    	set("type","axe");
    	set("bleeding",10);
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 110 );
	set( "value", ({ 300, "gold" }) );

}
