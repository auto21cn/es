#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed shield", "合金盾" );
	add( "id", ({ "shield" }) );
	set_short( "an alloyed shield", "合金盾" );
	set_long(
		"You see an alloyed shield. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"这是一面用某种不知名合金打造的盾，看起来相当重。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy" );
	set( "armor_class", 6 );
	set( "weight", 140 );
	set( "value", ({ 630, "silver" }) );
}
