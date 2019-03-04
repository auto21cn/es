#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "large pill", "大还丹" );
	add( "id", ({ "pill" }) );
	set_short( "大还丹" );
	set_long(@C_LONG
这是一粒用千年人参、雪莲等药材炼制成的大还丹，服用(eat)後可以
恢复大量体力。
C_LONG
	);
	set_healing( 100 );
	set( "no_sale", 1 );
        set( "weight", 30);
	set( "value", ({ 100, "gold" }) );
	set( "medication", 85 );
	set( "effect_critical", 50 );
}
