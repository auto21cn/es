#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp berry", "沼泽莓果" );
        set("no_sale",1);
	add( "id", ({"berry"}) );
	set_short( "沼泽莓果" );
	set_long(
		"这是一种有著难闻臭味的黑色沼泽莓果。你可以尝尝(taste)看。\n"
	);
	set( "ident", "SWAMP_BERRY" );
set("unit","颗");
	set( "savour","acrimony");
	set( "effect","simple_poison");
	set( "duration",3);
	set( "damage",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
