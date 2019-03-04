#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("poet dagger","诗人匕首");
       add("id",({"dagger",}) );
       set_short("诗人匕首");
       set_long(
           "一把匕首,看起来很像一只笔\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 14 );
    set("type","dagger");
	set( "min_damage", 7 );
	set( "max_damage", 16 );
	set( "weight", 25 );
	set( "value", ({ 450 , "silver" }) );

}
