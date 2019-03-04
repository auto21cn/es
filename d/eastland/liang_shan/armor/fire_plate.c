#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Fire-Cloud war armor","火云战甲");
        add("id",({"armor"}) );
        set_short( "a red-shining armor","火云战甲");
        set_long(
"This is a red, shining war armor which is sparkling wiht little fire.\n",
"这是一件火红色的战甲，不时闪耀著小小的火花。\n"
        );
        set( "unit", "件" );
        set( "weight",180 );
        set( "type", "body" );
        set( "armor_class", 31 );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "value", ({ 300, "gold" }) );
        set( "special_defense", ([ "none": 10,"cold":30 ]) );
}