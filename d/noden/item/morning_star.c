#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "morning star", "流星枪" );
	add( "id", ({ "star" }) );
   set_short( "流星枪" );
	set_long(
		"A huge heavy morning star.\n",
		"一个又大又重的流星枪，被这东西打到可不是好玩的。\n"
	);
	set( "type", "chain" );
	set( "weapon_class", 19 );
	set( "min_damage", 14 );
	set( "max_damage", 28 );
	set( "weight", 180 );
	set( "value", ({ 420, "silver" }) );
}
