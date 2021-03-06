#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "slime amulet", "护身符" );
	add( "id", ({ "amulet" }) );
	set_short( "史莱姆护身符" );
	set_long(
		"画著史莱姆符号的护身符。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 6 );
	set( "special_defense",
	      ([ "fire":5, "cold":5, "electric":-10, "acid":5, "energy":-5 ]) );
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
}
