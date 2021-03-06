#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "pruning scissors", "花剪" );
	add( "id", ({ "scissors", "scissor" }) );
	set_short( "花剪" );
	set_long(
		"这是一把用来修剪植物的大剪刀。\n"
	);
	set( "type", "shortblade" );
	set( "weapon_class", 8 );
	set( "min_damage", 3 );
	set( "max_damage", 10 );
	set( "weight", 80 );
	set( "nosecond", 1 );
	set( "value", ({ 65, "silver" }) );
	set_c_verbs( ({ "的%s往%s一夹" }) );
}
