#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Turtle plate", "海龟战甲");
        add( "id", ({ "plate" }) );
        set_short("Turtle plate", "海龟战甲");
        set_long(@AAA
这是一件以特殊龟甲打造而成，显的厚重沈稳。
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 40 );
        set( "defense_bonus", 10 );
        set("material","stone");
        set("special_defense",(["fire":5,"cold":15])) ;
        set( "weight", 500 );
        set( "value", ({ 1000, "silver" }) );
}
