#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("two-faced blade","三尖两刃刀");
       add("id",({"blade"}) );
       set_short("三尖两刃刀");
	   set_long(
           "这是一把造形奇特的宝刀，刀尖部有三个分叉，似乎可用来格开武器．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
    set("type","longblade");
	set( "min_damage", 13 );
	set( "max_damage", 26 );
	set("bleeding",5);
	set( "value", ({ 62, "gold" }) );
	set( "extra_skills",(["parry":10]));
	
}	
