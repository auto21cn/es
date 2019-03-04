#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "black crystal", "黑色魔水晶" );
	add( "id", ({ "crystal" }) );
	set_short( "black mystic crystal", "黑色魔水晶" );
	set_long(
	    "The black mystic crystal shinning terrible lights.\n",
	    "闪耀著淡淡的黑色光芒的神秘的水晶石.\n"
	);
	set( "no_sale", 1 );
	set( "unit", "个" );
	set( "echo_crystal",2);
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
}
