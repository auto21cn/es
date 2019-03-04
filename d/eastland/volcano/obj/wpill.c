#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "living pill", "续命药丸" );
	set_short( "续命药丸" );
        add ( "id" , ({"pill"}) );
	set_long(
	  "这是一颗续命药丸，是用千种奇珍药材炼成，据说可起死回生。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "颗" );
	set( "weight", 2 );
	set( "value", ({ 1, "gold" }) );
}
