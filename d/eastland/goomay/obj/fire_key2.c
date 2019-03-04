#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "fire key", "火焰之钥" );
	add( "id", ({ "key" }) );
	set_short( "a fire key", "火焰之钥" );
	set_long(
		"A magic key with fire shape.\n",
		"这是一个铸成火焰形的钥匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "FIRE_ELEMENT_KEY2" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
