#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "chain vest", "铠甲背心" );
	add( "id", ({ "vest" }) );
	set_short( "铠甲背心" );
	set_long(
		"一件轻便而又有良好保护效果的铠甲背心。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 17 );
	set( "weight", 140 );
	set( "value", ({ 470, "silver" }) );
}
