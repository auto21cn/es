#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult cloak", " 神秘披风");
        add( "id", ({ "cloak" }) );
        set_short("神秘披风");
        set_long(" 神秘披风\n");
        set("unit","件");
        set( "type", "cloak" );
        set( "material" , "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set( "value", ({ 3000, "silver" }) );
}
