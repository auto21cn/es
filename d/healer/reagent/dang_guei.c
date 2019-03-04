#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "dang guei", "当归" );
           set("no_sale",1);
	add("id", ({"dang","guei"}) );
	set_short( "当归" );
	set_long(
		"这是一块用来做药材的当归。你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "DANG_GUEI" );
	set( "unit", "块" );
        set( "weight", 2);
	set( "savour","bitter");
	set( "value", ({ 100, "silver" }) );
}
