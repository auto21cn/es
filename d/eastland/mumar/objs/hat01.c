#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("silken threads","纶巾");
        add("id",({"threads","hat"}) );
        set_short("纶巾");
        set_long(
"这是一顶纶巾，是东方大陆的军师才有资格戴的装备。\n"
        );
        set( "unit", "顶" );
        set( "weight", 50 );
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "value", ({ 1200, "silver" }) );
        set( "no_sale",1);
}
