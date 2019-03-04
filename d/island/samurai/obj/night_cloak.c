#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "night_shadow_cloak", "夜影披风");
        add( "id", ({ "cloak" }) );
        set_short("night_shadow_cloak", "夜影披风");
        set_long(@AAA
这是一件暗黑色的披风,可以让你在夜晚时,容易躲藏不被人发现
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set("material","leather");
        set("special_defense",(["cold": 10 ,"mental": 10 ]));
        set( "weight", 70 );
        set( "value", ({ 1200, "silver"
         }) );
}

