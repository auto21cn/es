#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_cloak", "武士披风");
        add( "id", ({ "cloak" }) );
        set_short("samurai_cloak", "武士披风");
        set_long(@AAA
一个武士们制式穿的披风
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 70 );
        set( "value", ({ 800, "silver"
         }) );
}
