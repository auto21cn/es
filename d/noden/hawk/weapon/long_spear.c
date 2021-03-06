#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long spear", "长矛" );
	add( "id", ({ "spear" }) );
	set_short( "长矛" );
	set_long(
		"这根长矛是用一枝长木棍，在末端绑上一块尖锐的岩石碎片制成。\n"
	);
	set( "unit", "枝" );
	set( "weight", 90 );
	set( "type", "thrusting" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 14 );
	set( "value", ({ 180, "silver" }) );
}
