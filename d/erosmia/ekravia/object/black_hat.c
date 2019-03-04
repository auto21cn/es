#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black hat", "黑色高帽" );
	add( "id", ({ "hat" }) );
   set_short( "黑色高帽子" );
	set_long(
		"这顶黑色、圆筒状的高帽子一向是魔术师们的注册商标。\n"
	);
	set( "unit", "顶" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 5 );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
}
