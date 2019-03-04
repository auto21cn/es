#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril helmet", "米苏理头盔");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "米苏理头盔");
        set_long(
                "A large helmet made of mithril .\n",
                "这是用米苏理金属所制成的头盔. \n"
                
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "weight", 66 );
        set( "value", ({ 1100, "silver" }) );
}



