#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark amulet","黑暗护身符");
        add("id",({"amulet"}) );
         set_short( "a dark amulet","黑暗护身符");
	set_long(
"这是一个曾被邪神 Yang 祝福过的护身符\n"
	);
	set( "no_sale",1);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "special_defense", ([ "evil":5, "divine":-10 ]) );
	set( "value", ({ 88, "gold" }) );
}
