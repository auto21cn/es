#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("song amulet","歌唱之符");
        add("id",({"amulet"}) );
         set_short( "a song amulet","歌唱之符");
	set_long(
"这是个歌唱护身符,似乎你能听到有歌声从里面传出\n"
	);
	set( "unit", "个" );
	set( "weight", 12 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "mental":6, "evil":3, "divine":-15 ]) );
	set( "value", ({ 150, "gold" }) );
}
