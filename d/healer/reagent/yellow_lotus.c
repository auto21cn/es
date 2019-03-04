#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow lotus", "黄莲" );
         set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "黄莲" );
	set_long(
		"这是一些由莲子心晒乾制成的药材。你可以尝尝(taste)他的味道。\n"
	);
	set( "unit","包");
	set( "ident", "YELLOW_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
