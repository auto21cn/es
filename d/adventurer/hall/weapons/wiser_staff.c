#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("wiser staff", "智者之杖");
	add( "id", ({ "staff" }) );
	set_short("a wiser staff", "智者之杖");
	set_long(
		"This is a wiser staff. Old adventurers love such staff as\n"
		"their weapon.\n",
		"这是一把智者之杖，通常是年老的冒险者用来防身的武器。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 70 );
	set( "value", ({ 430, "silver" }) );
}
