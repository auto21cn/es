#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_boots ", "武士长靴 ");
        add( "id", ({ "boots" }) );
        set_short("samurai_boots", "武士长靴 ");
        set_long(@AAA
一个武士们制式穿的长靴
AAA
        );
        set( "unit", "件"); 
        set( "type", "feet" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 100 );
        set( "value", ({ 600, "silver"
         }) );
}
