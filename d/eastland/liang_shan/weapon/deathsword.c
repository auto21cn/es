#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("death sword","丧门剑");
       add("id",({"sword"}) );
       set_short("丧门剑");
	   set_long(
           "这是一把锋利的宝剑，可以轻易的夺去敌人生命，故名丧门．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
        set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 29 );
	set( "weight", 100 );
	set( "value", ({ 81, "gold" }) );
	
}	
