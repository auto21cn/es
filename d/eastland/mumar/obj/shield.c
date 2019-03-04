#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "highsteel shield", "青钢大盾" );
	add( "id", ({ "shield" }) );
	set_short( "a highsteel shield", "青钢大盾" );
	set_long(
		"You see a large highsteel shield.\n",
		"这是一面青钢铸成的大盾，看起来十分坚固耐用。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "materia", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 70 );
	set( "value", ({ 610, "silver" }) );
}
