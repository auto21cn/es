#include <mudlib.h>
inherit "/std/reagent";

void create()
{
	set_name( "neo grass", "牛醉草" );
	add("id",({"grass","neo"}) );
	set_short("牛醉草" );
	set_long(
	"传说曾经有一只牛吃了牛醉草之後, 走路有如喝醉了一般, 所以乡下人就这样称呼它\n"
	"你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "NEO_GRASS" );
	set( "unit", "株" );
        set( "weight", 1 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 10, "silver" }) );
}

