#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("red pants","红短裤");
        add("id",({"pants"}) );
        set_short("红短裤");
        set_long(
"这是一件红色的短裤，通常在军中只有士官和宪兵才能穿。\n"
        );
        set( "unit", "件" );
        set( "weight", 30 );
        set( "type", "legs" );
        set( "material", "cloth" );
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "value", ({ 50, "silver" }) );
}
