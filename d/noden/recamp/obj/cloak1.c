#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Thunder Cloak", "雷电披风");
        add( "id", ({ "thunder","cloak" }) );
        set_short("Thunder Cloak", "雷电披风");
        set_long(@AAA
这是一件附有雷电精灵力量的披风
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 5);
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["electric":5])) ;
	set( "weight", 15 );
        set( "value", ({ 500, "silver" }) );
}
