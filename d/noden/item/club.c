#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "massive club", "巨木棒" );
	add( "id", ({ "club" }) );
   set_short( "巨木棒" );
	set_long(
		"这是一根和树干差不多粗的巨木棒。\n"
	);
	set( "unit", "根" );
	setup_weapon( "blunt", 25, 12, 29 );
	set( "weight", 330 );
	set( "value", ({ 30, "silver" }) );
}
