#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("vest","背心");
        add("id",({"vest","cloth"}) );
        set_short("背心");
        set_long(
"这是一件背心，通常是肌肉发达的人用来现肌肉用的。\n"
        );
        set( "unit", "件" );
        set( "weight", 70 );
        set( "type", "body" );
        set( "material", "cloth" );
        set( "armor_class", 10 );
        set( "defense_bonus", 1);
        set( "value", ({ 350, "silver" }) );
}
