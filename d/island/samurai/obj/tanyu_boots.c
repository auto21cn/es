#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu boots", "天羽战靴");
        add( "id", ({ "boots" }) );
        set_short("tanyu boots", "天羽战靴");
        set_long(@AAA
这是天羽剑派特有的战靴
AAA
        );
        set( "unit", "双"); 
        set( "type", "feet" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 660, "silver" }) );
}
