#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("iron hammer", "铁瓜□");
	add("id",({"hammer"}));
	set_short("铁瓜□");
	set_long(
		"这把铁□特地做成瓜的形状，使用时风阻可能较小。\n"
	);
	set( "unit", "把" );
	set( "weight", 130 );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 530, "silver" }) );
}
