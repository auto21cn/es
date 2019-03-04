#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "a_shu_la_chainmail", "阿修罗之铠");
        add( "id", ({ "chainmail" }) );
        set_short("a_shu_la_chainmail", "阿修罗之铠");
        set_long(@AAA
这是武士队长约修家传的铠甲 ，其上刻有一个阿修罗神的图案
可以让人感到一股浓浓的杀气
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 4 );
        set("material","heavy_metal");
        set( "weight", 250 );
        set( "value", ({ 1200, "silver" }) );
}
