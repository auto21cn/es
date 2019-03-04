#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("wooden stick","木头拐杖");
       add("id",({"stick",}) );
       set_short("木头拐杖");
       set_long(
           "用木头做成的拐杖\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 7 );
    set("type","blunt");
	set( "min_damage", 2 );
	set( "max_damage", 8 );
	set( "weight", 50 );
	set( "value", ({ 18, "silver" }) );

}
