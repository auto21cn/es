////#pragma save_binary
#include <mudlib.h>

inherit WEAPON;

void create()
{
       set_name("scalpel","解剖刀");
       add("id",({"scalpel",}) );
       set_short("解剖刀");
       set_long(
     	 "一把解剖刀,可以用来解剖尸体.也可以当护身武器。\n"
     	);
	
	set( "unit", "把" );
	set( "weight", 30 );
	set( "type","dagger");
	set( "min_damage",15);
	set( "max_damage",20);
	set( "weapon_class",20);
        set( "value", ({ 1000, "silver"} ) );

}
