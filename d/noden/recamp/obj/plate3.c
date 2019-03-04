#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "gin plate", "结晶铠甲");
        add( "id", ({ "plate" }) );
        set_short("gin plate", "结晶铠甲");
        set_long(@AAA
这是一件以石英晶石打造而成，穿上它显的英姿焕发，光芒四射。
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 35 );
        set( "defense_bonus", 10 );
        set("material","element");
        set("special_defense",(["fire":15])) ;
        set( "weight", 400 );
        set( "value", ({ 1000, "silver" }) );
}
