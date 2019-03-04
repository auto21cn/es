#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron axe", "大板斧" );
	add( "id", ({ "axe" }) );
	set_short( "a iron axe", "大板斧" );
	set_long(
		"You see an iron axe for cut trees.\n",
		"这是一把巨大的板斧，好像一把大扇子，没有力气的人可能拿不动它。\n"
	);
	set ("second",1);
	set( "unit", "把" );
	set( "weight", 200 );
	setup_weapon( "axe", 35, 15, 30 );
	set( "value", ({ 420, "silver" }) );
}
