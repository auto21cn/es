#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bloody stiletto", "血腥小刀" );
	add( "id", ({ "stiletto" }) );
   set_short( "血腥小刀" );
	set_long(
		"这是一把沾满血迹的锋利小刀 .... 小心！别割到你的手指。\n"
	);
	set( "unit", "把" );
	setup_weapon( "dagger", 16, 6, 14 );
	set( "weight", 30 );
	set( "bleeding", 25 );
	set( "second", 1 );
	set( "value", ({ 630, "silver" }) );
}
