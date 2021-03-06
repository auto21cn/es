#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("silk wedding gloves", "白色手套");
        add( "id", ({"gloves" }) );
        set_short("a silk wedding gloves", "白色手套");
        set_long(
                "A wedding gloves made of silk.\n",
                "一双丝质白色手套，专为和礼服搭配而设计。\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "material" ,"cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
        set( "no_sale", 1 );
        set( "value", ({ 1250, "silver" }) );
}
