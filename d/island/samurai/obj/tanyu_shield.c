#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu shield", "天羽盾");
        add( "id", ({ "shield" }) );
        set_short("tanyu shield", "天羽盾");
        set_long(@AAA
这是天羽剑派的特有之护盾
AAA
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 100 );
        set( "value", ({ 860, "silver" }) );
}
