#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("wood oar", "枣木槊");
	add("id",({"oar"}));
	set_short("枣木槊");
	set_long(
		"这是一把枣木制的大船桨，给它打上一下可不好玩。\n"
	);
	set( "unit", "根" );
	set( "weight", 170 );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 12 );
	set( "max_damage", 23 );
	set( "value", ({ 610, "silver" }) );
}
