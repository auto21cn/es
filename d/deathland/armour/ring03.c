#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dwarven royal ring","矮人皇室戒指");
        add("id",({"ring"}) );
         set_short( "a dwarven royal ring","矮人皇室戒指");
	set_long(
"This is a dwarven royal ring. \n"
"这是一个矮人皇室历代相传的戒指,但是随著莫拉德二世一起失踪了\n"
	);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7);
	set( "special_defense", ([ "divine":5, "cold":-8 ]) );
	set( "value", ({ 388, "gold" }) );
    set( "no_sale",1);
}
