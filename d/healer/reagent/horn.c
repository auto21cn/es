#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "rhinoceros horn", "犀牛角" );
              set("no_sale",1);
	add( "id", ({ "horn" }) );
	set_short( "a rhinoceros horn", "犀牛角" );
	set_long(
		"You see a horn of rhinoceros, used to be a kind of reagent.\n",
		"这是犀牛头上的角，从前人们往往将它拿来当作珍贵的药材。你可以尝尝(taste)看。\n"
	);
	set( "ident", "RHINOCEROS_HORN" );
	set( "unit", "枝" );
        set( "weight", 4 );
	set( "effect","weak");
	set( "frequency",3);
	set( "difference",3);
	set( "value", ({ 680, "silver" }) );
}
