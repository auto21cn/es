#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur skirt", "兽皮裙子" );
	add( "id", ({ "skirt" }) );
   set_short( "兽皮裙子" );
	set_long(
		"这是一件肮脏的兽皮裙子，上面的毛皮东掉一块，西秃一块，十分难看。\n"
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "leather" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-2, "cold":1 ]) );	
	set( "value", ({ 170, "silver" }) );
}
