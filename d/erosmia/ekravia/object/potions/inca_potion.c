#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "inca potion", "印卡药水" );
	add( "id", ({ "potion", "inca" }) );
	set_short( "印卡药水" );
	set_long( @LONG
这是由爱卡拉维亚附近特产的一种昆虫, 与一些其他的药材经魔法调配而
成的药水, 具有少许的医疗能力。
LONG
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
