#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("huge mithril helmet", "巨米苏理头盔");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "巨米苏理头盔");
        set_long(
                "A huge helmet made of mithril .\n",
                "这是用米苏理金属所制成的头盔. \n"
                
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 80 );
        set( "value", ({ 1800, "silver" }) );
}



