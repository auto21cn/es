#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "fruit_cloth", "布" );
	set_short( "布" );
	set_long(
		"这是专门铺在人参果树下接果子所用的布。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "块" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
