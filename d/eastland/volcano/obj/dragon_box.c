#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "dragon_box", "黑龙的盒子" );
	set_short(  "黑龙的盒子" );
        add ( "id" , ({"box"}) );
	set_long(
	  "这是曾属於黑龙的盒子，据说具有强大的力量，足以毁天灭地。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "个" );
	set( "weight", 10 );
	set( "value", ({ 1, "gold" }) );
}
