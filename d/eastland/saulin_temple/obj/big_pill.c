#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "large herb pill", "大块灵芝" );
	add( "id", ({ "pill" }) );
	set_short( "大块灵芝" );
	set_long(
		"这是一大块成形灵芝的精华，服用(eat)後可以恢复不少体力。\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "weight", 20 );
	set( "value", ({ 8, "gold" }) );
	set( "unit", "块" );
	set( "medication", 40 );
	set( "effect_critical", 70 );
}
