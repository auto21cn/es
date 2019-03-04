#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Longsword of Nightmare","恶梦长剑");
        add("id",({"sword","longsword","nightmare"}) );
        set_short("恶梦长剑");
      	set_long(
           "一把会让你的敌人产生恶梦的锋利长剑\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 33 );
	set( "weight", 100 );
	set( "value", ({ 320, "gold" }) );

}

