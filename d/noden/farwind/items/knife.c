#include <mudlib.h>

inherit WEAPON;

void create()
{
	if ( clonep(this_object()) )
	set_default_ob(base_name(this_object()));
else {
	set_name( "knife", "小刀" );
	set_short( "小刀" );
	set_long(
		"一把毫不起眼的小刀。\n"
	);
	set( "unit", "把" );
        set( "weight", 20 );
	set( "weapon_class", 5 );
	set( "type", "dagger" );
	set( "min_damage", 2 );
	set( "max_damage", 5 );
	set( "second", 1 );
	set( "value", ({ 10, "silver" }) );
}
}
