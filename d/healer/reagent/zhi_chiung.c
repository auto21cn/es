#include <mudlib.h>
inherit "/std/reagent";

void create()
{
	set_name( "zhi chiung", "知穹草" );
	add("id",({"grass","chiung"}) );
	set_short("知穹草" );
	set_long(
	"知穹草生长在宽广的草原, 矮矮的, 大约只有两寸。\n"
	"你可以尝尝(taste)他的味道。\n"
	);
	set( "ident", "ZHI_CHIUNG" );
	set( "unit", "株" );
        set( "weight", 1 );
	set( "savour","bitter");
	set( "effect","weak");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 30, "silver" }) );
}

