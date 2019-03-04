#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white bracers", "白云石手钏" );
	add( "id", ({ "bracers" }) );
	set_short( "白云石手钏" );
	set_long(
		"这是一对用某种不知名的白石头造出的手环，看起来相当重。\n"
	);
	set( "unit", "双" );
	set( "type", "hands" );
	set( "armor_class", 5 );
        set("material","stone");
	set( "weight", 70 );
	set( "value", ({ 1000, "silver" }) );
}
