#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "hawtor chicken soup", "华陀鸡汤" );
	add( "id", ({ "soup" }) );
	set_short( " hawtor chicken soup", "华陀鸡汤" );
	set_long(
		"The chicken soup,maybe you can drink it.\n",
		"一罐华陀鸡汤,看起来十分令人难以下□但是似乎是一种补药\n"
	);
	set_healing( 100 );
	set( "no_sale", 1 );
	set( "unit", "罐" );
	set( "weight", 30 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 40 );
	set( "effect_critical", 80 );
}
