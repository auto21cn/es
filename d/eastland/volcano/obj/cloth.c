#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "square cloth", "方布" );
	set_short( "方布" );
	set_long(
"这是一块约有三尺见方大的布，上面还绣了许\多图案，看起来好像是天上仙境。\n"
	);
        add( "id", ({"cloth"}) );
	set( "no_sale", 1 );
	set( "unit", "块" );
	set( "weight", 2 );
	set( "value", ({ 1, "silver" }) );
}
