#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crystal ring", "水晶戒指" );
	add( "id", ({ "ring" }) );
	set_short( "a crystal ring", "水晶戒指" );
	set_long(
		"You see a crystal ring. It is glowing in a soft aura.\n",
		"这个水晶戒指上面镶著一粒鲜红色的水晶，水晶周围似乎围绕著一\n"
		"圈水气，被水晶内部发出的微光照得朦朦胧胧。\n"
	);
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "energy":5, "electric":-8 ]) );
	set( "weight", 3 );
	set( "value", ({ 1840, "silver" }) );
}
