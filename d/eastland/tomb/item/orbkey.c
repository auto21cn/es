#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "golden dragon orb", "金龙珠" );
	add( "id", ({ "key","orb" }) );
	set_short( "金龙珠" );
	set_long(
		"这是一颗金色的珠子，上面流动著奇异的光芒。\n"
	);
	set( "unit", "颗" );
	set( "to_lock", "TOMBKEY_1" );
	set( "weight", 5 );
	set( "value", ({ 10, "copper" }) );
	set( "no_sale", 1 );
}
