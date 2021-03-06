#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("floral cloak", "绯红团花袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("floralcloak","绯红团花袍");
        set_long(
                "This is a red cloak with some floral mark.\n",
                "一件双层绯红的披风，绣了许\多美丽的花纹．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 1 );
        set( "weight", 90 );
        set( "value", ({ 1000, "silver" }) );
}