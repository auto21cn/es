#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "chai hu", "柴胡" );
          set("no_sale",1);
	add("id",({"chai","hu"}) );
	set_short( "柴胡" );
	set_long(
		"这是一支用来制药的柴胡。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "CHAI_HU" );
	set( "unit", "支" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",2);
	set( "difference",2);
	set( "value", ({ 50, "silver" }) );
}
