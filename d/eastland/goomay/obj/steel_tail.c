#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "highsteel tail armor", "精钢尾甲" );
	add( "id", ({ "tail","armor" }) );
	set_short( "a high \steel tail armor ", "精钢尾甲" );
	set_long(
		"You see a steel tail armor .\n",
		"这是一套纯钢打造的尾甲，有高度的防御力。\n"
	);
	set( "unit", "套" );
	set( "type", "tail" );
        set("material","heavy_metal");
	set( "weight", 100 );
	set("armor_class",7);
	set( "value", ({ 450, "silver" }) );
}
