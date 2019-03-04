#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "medlar", "枸杞子" );
         set("no_sale",1);
	set_short( "a medlar fruit", "枸杞子" );
	set_long(
		"You see a medlar fruit which are used as reagents the most.\n",
		"这是一种用来做药材的枸杞子。你可以尝尝(taste)看。\n"
	);
	set( "ident", "MEDLAR" );
	set( "unit", "包" );
        set( "weight", 2 );
	set( "savour","sweet");
        set("value", ({40,"silver" }) );
}
