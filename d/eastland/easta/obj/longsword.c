#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel longsword", "长剑" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "青钢长剑" );
	set_long("这是一把质地坚硬，青钢铸成的长剑。\n");
	set( "unit", "把" );
	set( "weight", 90 );
	setup_weapon( "longblade", 22, 9, 20 );
	set( "bleeding", 5 );
	set( "value", ({ 520, "silver" }) );
}

