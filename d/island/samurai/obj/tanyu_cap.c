#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cap", "天羽头巾");
        add( "id", ({ "cap" }) );
        set_short("tanyu cap", "天羽头巾");
        set_long(@AAA
这是天羽剑派特有的头巾
AAA
        );
        set( "unit", "件"); 
        set( "type", "head" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","cloth");
        set( "weight", 30 );
        set( "value", ({ 600, "silver" }) );
}
