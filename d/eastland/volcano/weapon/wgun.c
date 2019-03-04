#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("toy gun","玩具枪");
       add("id",({"gun",}) );
       set_short("玩具枪");
       set_long(
           "一把玩具枪\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 5 );
        set( "type","dagger");
	set( "min_damage", 5 );
	set( "max_damage", 10 );
	set( "weight", 50 );
	set( "value", ({ 15, "silver" }) );

}
