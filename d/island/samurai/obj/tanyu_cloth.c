#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloth", "天羽战衣");
        add( "id", ({ "cloth","clothes" }) );
        set_short("tanyu cap", "天羽战衣");
        set_long(@AAA
这是天羽剑派特有的战斗装，有不错的防护力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 25 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 130 );
        set( "value", ({ 700, "silver" }) );
}
