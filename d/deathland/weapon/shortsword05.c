#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("holy shortsword","神圣短剑");
        add("id",({"sword","shortsword"}) );
       set_short("神圣短剑");
       set_long(
         "一把神圣的短剑,据说是由神圣守卫使用的神兵利器 .\n"
               );
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 35 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 22 );
	set( "max_damage", 33 );
        set( "weight",95 );
	set( "value", ({ 3000, "silver" }) );
}
