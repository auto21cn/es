#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("sable skin","貂皮");
        add("id",({"skin","cloak"}) );
        set_short("貂皮");
        set_long(
"这是一件皮草，据说可以防寒避雨。\n"
        );
        set( "unit", "件" );
        set( "weight",70 );
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "value", ({ 1800, "silver" }) );
        set( "no_sale",1);
        set( "special_defense",(["cold":15]));
}
