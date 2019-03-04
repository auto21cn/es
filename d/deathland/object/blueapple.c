#include "../echobomber.h"

inherit POTION;

void create()
{
	potion::create();
	set_name( "blue apple juice", "蓝苹果汁" );
	add( "id", ({ "juice" }) );
	set_short( " blue apple juice", "蓝苹果汁" );
	set_long(
		"The juice is blue,maybe you can drink it.\n",
		"一瓶蓝苹果汁,看起来有点恶心但是应该是可以喝的。\n"
	);
	set_healing( 90 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 30 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 30 );
	set( "effect_critical", 100 );
}
