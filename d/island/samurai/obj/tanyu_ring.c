#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu ring", "天羽指环");
        add( "id", ({ "ring" }) );
        set_short("tanyu ring", "天羽指环");
        set_long(@AAA
这是天羽剑派的掌们信物之一，天羽指环
AAA
        );
        set( "unit", "个"); 
        set( "type", "finger" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set("material","light_metal");
        set( "weight", 20 );
        set( "value", ({ 660, "silver" }) );
}
