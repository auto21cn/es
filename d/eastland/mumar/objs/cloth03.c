#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("quaspect robe","四象玄袍");
        add("id",({"robe"}) );
        set_short("四象玄袍");
        set_long(
"四象玄袍，是诸葛不明最爱穿的一件道袍。\n"
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
        set( "value", ({ 2000, "silver" }) );
        set( "no_sale",1);
}
