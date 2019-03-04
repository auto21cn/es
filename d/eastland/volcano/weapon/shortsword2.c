#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("blue_water shortsword","青水短剑");
       add("id",({"shortsword"}) );
       set_short("青水短剑");
       set_long(
           "一把半透明的短剑，剑中似乎有水流动\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set( "type","shortblade");
        set( "second", 1);
	set( "min_damage", 23 );
	set( "max_damage", 36 );
	set( "weight", 200 );
	set( "value", ({ 500, "gold" }) );
}
