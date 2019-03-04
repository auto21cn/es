#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("golden cloth","金镂玉衣");
        add("id",({"cloth"}) );
        set_short("金镂玉衣");
        set_long(
"这是一件皇上御赐的金镂衣，是无数的玉片用金丝串成的。\n"
        );
        set( "unit", "件" );
        set( "weight",180 );
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 29 );
        set( "defense_bonus", 7 );
        set( "special_defense",(["fire":10,"cold":-5,"evil":5,"none":1]) );
        set( "value", ({ 3000, "silver" }) );
        set( "no_sale",1);
}
