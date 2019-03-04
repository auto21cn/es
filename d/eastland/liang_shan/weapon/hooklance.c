#include "takeda.h"


inherit WEAPON;

void create()
{
       set_name("scythe-lance","钩镰枪");
       add("id",({"lance"}) );
       set_short("钩镰枪");
	   set_long(
           "这是一把造型奇特的枪，末端连著一把小镰刀．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
        set("type","thrusting");
	set( "min_damage", 21 );
	set( "max_damage", 28 );
	set( "weight", 130 );
	set( "value", ({ 42, "gold" }) );
        set( "nosecond",1);
}
	
