#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "green stick", "青竹棒" );
	add( "id", ({ "stick" }) );
   set_short( "青竹棒" );
	set_long(
		"你看到一根细细长长的嫩绿色竹棒。\n"
	);
	set( "unit", "根" );
	set( "weight", 20 );
   setup_weapon( "bo", 3, 4, 6 );
	set( "value", ({ 5, "silver" }) );
}
