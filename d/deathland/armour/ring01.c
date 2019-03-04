#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("dark ring","黑暗戒指");
        add("id",({"ring"}) );
         set_short( "a dark ring","黑暗戒指");
	set_long(
"This is a ring blessed by Evil God -- Yang. \n"
"这是一个曾被邪神 Yang 祝福过的戒指,它的魔力可以保护你避免敌人的重击\n"
	);
	set( "unit", "个" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material" ,"element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
    set( "special_defense", ([ "evil":5, "divine":-8 ]) );   
	set( "value", ({ 288, "gold" }) );
}
