#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("toy dagger","玩具匕首");
       add("id",({"dagger",}) );
       set_short("玩具匕首");
       set_long(
           "一把玩具匕首\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 4 );
        set( "type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 40 );
	set( "value", ({ 10, "silver" }) );

}
