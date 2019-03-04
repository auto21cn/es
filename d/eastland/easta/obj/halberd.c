#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel halberd", "长戈" );
	add( "id", ({ "halberd" }) );
	set_short( "青钢长戈" );
	set_long("这是一把质地坚硬，青钢铸成的长戈。\n");
	set( "unit", "把" );
	set( "weight", 190 );
	setup_weapon( "polearm", 30, 17, 34 );
	set( "bleeding", 10 );
	set( "nosecond", 1 );
	set( "value", ({ 1420, "silver" }) );
}
