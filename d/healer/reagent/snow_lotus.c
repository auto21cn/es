#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "snow lotus", "雪莲" );
        set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "雪莲" );
	set_long(
		"哇!这是由雪莲花朵晒乾制成的药材, 可说百年难得一见!!你可以尝尝(taste)他的味道。\n"
	);
	set( "unit","朵");
	set( "ident", "SNOW_LOTUS" );
	set( "savour","sweet");
	set( "effect","weak");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 1000, "silver" }) );
}
