#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ginseng", "人参" );
	set_short( "a ginseng", "人参" );
	set_long(
		"You see a ginseng which are used as reagents the most.\n",
		"这是一根用来做药材的人参。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "GINSENG" );
         set("no_sale",1);
	set( "unit", "根" );
        set( "weight", 2 );
	set( "savour","bitter");

	set( "value", ({ 100, "silver" }) );
}
