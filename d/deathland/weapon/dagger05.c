#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("scalpel","手术刀");
       add("id",({"dagger",}) );
       set_short("手术刀");
       set_long(
     	 "一把专门在手术时使用的小刀.\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 24 );
    set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 24 );
	set( "weight", 32 );
	set( "extra_skills", (["operation":10]) );
	set( "value", ({ 1900 , "silver" }) );

}
