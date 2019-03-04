#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "buckler", "圆盾" );
   set_short( "圆盾" );
	set_long(
		"这个圆盾已经相当旧了，上面还被武器砍出几道缺口，不过看起来仍然\n"
		"相当耐用。\n"
	);
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "weight", 70 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "value", ({ 285, "silver" }) );
}
