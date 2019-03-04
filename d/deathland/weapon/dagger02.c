#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name(" short dagger","短匕首");
       add("id",({"dagger",}) );
       set_short("短匕首");
       set_long(
           "一把像玩具一样的匕首\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 9 );
    set("type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 8 );
	set( "weight", 25 );
	set( "value", ({ 50 , "silver" }) );

}
