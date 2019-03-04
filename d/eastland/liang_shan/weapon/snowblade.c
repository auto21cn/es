#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("snow iron-blade","雪花镔铁刀");
       add("id",({"iron-blade","blade",}) );
       set_short("雪花镔铁刀");
	   set_long(
           "一把用上好镔铁打造成的刀，刀刃反射森森的寒光，看来相当锋利．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 37 );
        set("type","longblade");
	set( "min_damage", 25 );
	set( "max_damage", 37 );
	set( "weight", 140 );
	set( "nosecond", 1 );
        set( "bleeding", 10 );
	set( "value", ({ 740, "gold" }) );
	
}	
