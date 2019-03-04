#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bone blade", "骨刀" );
	add( "id", ({ "blade" }) );
	set_short( "a bone blade", "骨刀" );
	set_long(
		"这把骨刀看起来十分寻常，是用一般大鱼的脊椎骨削成的。\n"
	);
	set( "unit", "把" );
	set( "weight", 120 );
	setup_weapon( "longblade", 8, 6, 9);
//	set( "bleeding", 6 );
	set( "value", ({ 45, "gold" }) );
}
