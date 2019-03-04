#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu armband", "天羽臂环");
        add( "id", ({ "armband" }) );
        set_short("tanyu armband", "天羽臂环");
        set_long(@AAA
这是天羽剑派特有的臂环，有不错的防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "arms" );
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set("material","light_metal");
        set( "weight", 30 );
        set( "value", ({ 760, "silver" }) );
}
