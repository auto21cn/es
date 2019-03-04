#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel blade", "钢刀" );
	add( "id", ({ "blade" }) );
   set_short( "钢刀" );
	set_long(
		"这把钢刀看起来十分寻常，宽背薄刃，重量趁手。\n"
	);
	set( "unit", "把" );
	set( "weight", 120 );
	setup_weapon( "longblade", 15, 10, 17 );
	set( "bleeding", 5 );
	set( "value", ({ 43, "gold" }) );
}
