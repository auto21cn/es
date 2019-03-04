#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Longsword of Molader","莫拉德长剑");
        add("id",({"sword","longsword",}) );
        set_short("莫拉德长剑");
      	set_long(
           "一把莫拉德皇室专用的锋利长剑\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
    set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 100 );
	set( "value", ({ 220, "gold" }) );

}
