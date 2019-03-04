#include "../asterism.h"

inherit WEAPON;

void create()
{
        set_name("Mithril LongSword","米苏里长剑");
        add("id",({"sword","longsword",}) );
        set_short("米苏里长剑");
      	set_long(
           "矮人用米苏里金属打造成的长剑\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 28 );
        set("type","longblade");
	set( "min_damage", 10 );
	set( "max_damage", 28 );
	set( "weight", 100 );
	set( "value", ({ 120, "gold" }) );

}
