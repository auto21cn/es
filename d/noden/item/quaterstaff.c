#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "oak quaterstaff", "橡木杖" );
	add( "id", ({ "quaterstaff", "staff" }) );
   set_short( "橡木杖" );
	set_long(
		"一把用坚硬的橡木做成的木杖，它的尖端包著一个铁箍。\n"
	);
	set( "unit", "根" );
	setup_weapon( "blunt", 15, 3, 10 );
	set( "weight", 65 );
	set( "value", ({ 120, "silver" }) );
}
