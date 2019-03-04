#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("break sword of Wind","风之断剑");
        add("id",({"sword"}) );
       set_short("风之断剑");
       set_long(
         "一把断掉的神剑,据说它能随著风而飞入敌人的心脏\n"
               );
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 23 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 16 );
	set( "max_damage", 25 );
	set( "weight", 71 );
	set( "value", ({ 1800, "silver" }) );
}
