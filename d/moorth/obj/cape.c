#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black cape", "黑色披风" );
	add( "id", ({ "cape" }) );
	set_short( "a black cape", "黑色披风" );
	set_long(
		"You see a black cape with the symbol of Moorth Army on it.\n"
		"这是一件黑色的披风，上面有一个默尔斯军队的标志。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth" );
	set( "armor_class", 4 );
	set( "defense_bonus", 6);
	set( "weight", 70 );
	set( "special_defense", ([ "evil":5,"divine":-7 ]) );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}
