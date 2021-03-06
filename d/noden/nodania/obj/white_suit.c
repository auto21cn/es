#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white suit", "白色诗人服" );
	add( "id", ({ "suit" }) );
	set_short( "白色诗人服" );
	set_long(
		"这件衣服是用上等的布料制成的，看起来很漂亮也很昂贵。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 2);
	set( "special_defense", ([ "magic":2, "fire":-3 ]) );
	set( "weight", 60 );
	set( "value", ({ 76, "gold" }) );
}
