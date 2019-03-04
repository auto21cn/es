#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "The statue of Goddess", "月神像" );
	add( "id", ({ "statue" }) );
	set_short( "月神像" );
	set_long(
		"这是一尊翠玉精雕的女神像。\n"
	);
	set( "unit", "尊" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

