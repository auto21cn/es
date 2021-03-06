#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "looter's dagger", "匕首" );
	add( "id", ({ "dagger" }) );
   set_short( "盗墓者匕首" );
	set_long(
    "这是一把长而锋利的匕首，在柄的末端还有许多钩子，盗墓者通常用这种\n"
		"匕首挖取石棺或雕像上的宝石。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weight", 40 );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 11 );
	set( "second", 1 );
	set( "value", ({ 420, "silver" }) );
}
