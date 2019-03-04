#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "purple ratter", "紫心藤" );
	add("id",({"ratter"}) );
	set_short("紫心藤" );
	set_long(
		"这根紫心藤表面是绿色的, 可是切面中心却有异样的紫色。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "PURPLE_RATTER" );
	set( "unit", "根" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 100, "silver" }) );
}

