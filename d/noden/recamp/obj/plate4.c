#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Wooden plate", "木化铠甲");
        add( "id", ({ "plate" }) );
        set_short("Wooden plate", "木化铠甲");
        set_long(@AAA
这是一件以木质编织而成的铠甲，显的相当神奇有趣。
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 10 );
        set("material","wood");
        set("special_defense",(["electric":15])) ;
        set( "weight", 350 );
        set( "value", ({ 1000, "silver" }) );
}
