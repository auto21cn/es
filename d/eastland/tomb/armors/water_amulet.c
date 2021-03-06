#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "water amulet", "水之护符" );
	add( "id", ({ "amulet" }) );
	set_short( "水之护符" );
	set_long(
		"这是一张奇异的护符，闪耀著淡蓝色的光芒，你可以感受到它充满了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "cold":15, "fire": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 900, "silver" }) );
}
