#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "fire element", "火之精" );
	add( "id", ({ "element","fire" }) );
	set_short( "a fire element", "火之精" );
	set_long(
		"You see a element of fire . \n",
		"这是一颗罕见的火焰精华。\n"
	);
	set( "unit", "颗" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

