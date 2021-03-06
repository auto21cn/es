#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden cloak", "挽绒金绣丝罗袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("golden cloak","挽绒金绣丝罗袍");
        set_long(
                "This is a golden beautiful cloak.\n",
                "一件用金丝和绒布做成的披风，非常灿烂夺目．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 1120, "silver" }) );
}