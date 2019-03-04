#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("pu blade","朴刀");
       add("id",({"blade"}) );
       set_short("朴刀");
	   set_long(
           "这是一把非常普通的刀子，是梁山泊强盗的制式武器．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 17 );
    set("type","longblade");
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "weight", 65 );
	set("bleeding",5);
	set( "value", ({ 42, "gold" }) );
	
}	
