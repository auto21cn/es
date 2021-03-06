#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silk gloves", "丝质手套");
        add( "id", ({"gloves" }) );
        set_short("a silk gloves", "丝质手套");
        set_long(
                "An gloves made of silk.\n",
                "一双丝质手套,可以让武器的使用更加流畅\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
        set( "defense_bonus", 2 );
        set( "extra_skills", ([ "parry":3 ]) );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}
