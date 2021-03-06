#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "padded robe", "软甲护袍" );
	add( "id", ({ "robe" }) );
	set_short( "a padded robe", "软甲护袍" );
	set_long(
		"You see a long robe with padded metal pieces. It looks light and\n"
		"protective.\n",
		"这是一件长型护袍，上面用金属片镶在肩部、前胸与後背，看起来相当轻便\n"
		"而且具不错的保护效果。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "cold":4, "electric":-5 ]) );
	set( "weight", 80 );
	set( "value", ({ 1300, "silver" }) );
}
