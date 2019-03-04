#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "herb pill", "小块灵芝" );
	add( "id", ({ "pill" }) );
	set_short( "小块灵芝" );
	set_long(
		"这是一块成形灵芝的精华，服用(eat)後可以恢复一些体力。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "weight", 10 );
	set( "value", ({ 5, "gold" }) );
	set( "unit", "块" );
	set( "medication", 20 );
	set( "effect_critical", 80 );
}
