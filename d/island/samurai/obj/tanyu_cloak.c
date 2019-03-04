#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloak", "天羽披风");
        add( "id", ({ "cloak" }) );
        set_short("tanyu cloak", "天羽披风");
        set_long(@AAA
这是天羽剑派特有的披风，有不错的防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 660, "silver" }) );
}
