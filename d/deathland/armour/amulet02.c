#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark bishop amulet","黑暗主教护身符");
        add("id",({"amulet"}) );
         set_short( "a dark bishop amulet","黑暗主教护身符");
	set_long(
"这是一个曾被邪神 Yang 祝福过的护身符\n"
	);
	set( "no_sale",1);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "evil":7, "divine":-15 ]) );
	set( "value", ({ 188, "gold" }) );
}
