#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "丝质领巾");
        add( "id", ({ "scarf" }) );
        set_short("a scarf for Gentlemen", "丝质领巾");
        set_long(
                "A beautiful scarf for gentlemen on meeting.\n",
                "一条男士在正式场合结的领巾。\n"
        );
        set("unit","条");
        set( "type", "cloak" );
        set( "material","cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 55 );
        set( "no_sale", 1 );
        set( "value", ({ 1800, "silver" }) );
}
