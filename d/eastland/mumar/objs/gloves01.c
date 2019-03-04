#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("silk gloves", "丝质手套");
        add( "id", ({"gloves" }) );
        set_short("丝质手套");
        set_long(
                "一双丝质手套,可以让武器的使用更加流畅\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set( "armor_class", 1 );
        set( "defense_bonus", 4 );
        set( "material","cloth" );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}
