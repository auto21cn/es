#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "feather cloak", "羽毛披风" );
	add( "id", ({ "feather","cloak" }) );
   set_short( "羽毛披风" );
	set_long(
		"这件羽毛做成的披风看起来很....新潮，如果你穿著它上街的话。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "leather" );
	set( "armor_class", 4 );
    set( "special_defense",([ "fire":-1 ]) );
	set( "weight", 70 );
	set( "value", ({ 20, "silver" }) );
}
