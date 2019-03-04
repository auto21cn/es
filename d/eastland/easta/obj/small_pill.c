#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "small pill", "小还丹" );
	add( "id", ({ "pill" }) );
	set_short( "小还丹" );
	set_long(@C_LONG
这是一粒用人□、灵芝等药材炼制成的小还丹，服用(eat)後可以
恢复一些体力。
C_LONG
	);
	set_healing( 60 );
	set( "no_sale", 1 );
        set( "weight", 20);
	set( "value", ({ 45, "gold" }) );
	set( "medication", 50 );
	set( "effect_critical", 60 );
}
