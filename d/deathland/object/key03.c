#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "grey key", "灰色钥匙" );
	add( "id", ({ "key" }) );
	set_short( "a grey key", "灰色钥匙" );
	set_long(
		"A grey key.\n",
		"这是一把灰色钥匙,由於\许\久未使用所以原有的光泽完全消退了\n"
	);
	set( "unit", "把" );
	set( "to_lock", "ECHO_VILLAGE_ARCHDOOR" );
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
