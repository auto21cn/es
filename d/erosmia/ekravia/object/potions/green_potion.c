#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "green potion", "翠绿药水" );
	add( "id", ({ "potion", "green" }) );
	set_short( "翠绿药水" );
	set_long( @LONG
这是爱卡拉维亚镇上老炼金术师精心提炼的密药, 拥有绝佳的治疗效果。
LONG
	);
	set_healing( 95 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 15 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 70 );
	set( "effect_critical", 80 );
}
