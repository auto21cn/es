#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "fruit", "果实" );
	add("id",({"fruit"}) );
	set_short("果实" );
	set_long(
		"这颗果实看起来很像苹果, 但是表面布满细细的绒毛。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "NO_NAME_FRUIT" );
	set( "unit", "颗" );
        set( "weight", 2 );
	set( "savour","sweet");
	set( "effect","simple_poison");
	set( "duration",4);
	set( "damange",6);
	set( "no_sale",1);
}

