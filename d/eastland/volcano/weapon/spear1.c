#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("long spear of Black","黑长矛");
       add("id",({"spear"}) );
       set_short("黑长矛");
       set_long(
           "一把通体乌黑的钢长矛，可以无声无息的刺入敌人的心脏。\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set( "type","thrusting");
	set( "min_damage", 20 );
	set( "max_damage", 40 );
	set( "weight", 120 );
	set( "value", ({ 200, "gold" }) );
}
