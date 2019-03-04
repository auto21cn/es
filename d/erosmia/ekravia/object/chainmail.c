#include "../ekravia.h"
inherit ARMOR;

void	create()
{
	set_name("chainmail", "□甲");
	add( "id", ({ "mail","chainmail" }) );
	set_short( "□甲" );
	set_long(
		"一件金属制成的□甲。\n"
	);
	set("unit","件");
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 2 );
	set( "weight", 150 );
	set( "value", ({ 600, "silver" }) );
}






