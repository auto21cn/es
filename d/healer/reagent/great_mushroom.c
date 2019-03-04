#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "great mushroom", "灵芝" );
	add("id",({"mushroom"}) );
	set_short("灵芝" );
	set_long(
		"这块灵芝是用来做药引的, 不能直接生吃, 不过你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "GREAT_MUSHROOM" );
	set( "unit", "块" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "value", ({ 120, "silver" }) );
}
