#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("cloak of couples", "黑披风");
        add( "id", ({ "cloak" }) );
        set_short( "黑披风");
        set_long(@C_LONG
黑披风是由天山二老采集十头黑熊的皮所制成的。 由二老之一掼用毒的鹤老在上
面涂上一层薄薄防毒药物。如果你怕被人下毒, 那你可以穿这件披风哟!!
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","leather") ;
        set( "armor_class", 5 );
        set( "defense_bonus",2 );
        set("special_defense",
              (["poison":10]) );
        set( "weight", 90 );
        set( "value", ({ 100, "gold" }) );
}



