#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed platemail", "合金盔甲" );
	add( "id", ({ "plate", "platemail", "mail" }) );
	set_short( "a suit of alloyed playemail", "合金盔甲" );
	set_long(
		"You see a suit of alloyed platemail. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"这是一套用某种不知名合金打造的盔甲，看起来相当重。\n"
	);
	set( "unit", "副" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 25 );
	set( "weight", 300 );
	set( "value", ({ 1030, "silver" }) );
}
