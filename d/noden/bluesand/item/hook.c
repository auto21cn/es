#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel hook", "钢钩" );
	add( "id", ({ "hook" }) );
   set_short( "钢钩" );
	set_long(
		"这个钢钩上有一个保护手部的铁套，不知道为什麽海盗都喜欢用这种武器？\n"
	);
	set( "unit", "把" );
	setup_weapon( "unarmed", 21, 9, 28 );
	set( "weight", 50 );
	set( "value", ({ 940, "silver" }) );
}
