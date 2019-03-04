#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "vigor potion", "活力药水" );
	add( "id", ({ "potion", "vigor" }) );
	set_short( "活力药水" );
	set_long( @LONG
这是一瓶透明无色的药水, 药瓶瓶底的标签这麽写著:
「你觉得疲惫不堪吗? 那麽这瓶奇异的药水可以使你虚弱的身体立刻恢复
  活力!」
LONG
	);
	set_healing( 5 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 15 );
	set( "value", ({ 500, "silver" }) );
	set( "medication", -90 );
	set( "effect_critical", 0 );
}
