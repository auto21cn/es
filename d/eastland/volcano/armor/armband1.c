#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("prayer armband", "祈祷者手环");
        add( "id", ({ "armband" }) );
        set_short("祈祷者手环");
        set_long(
                "这是一般祈祷者用的手环。\n"
        );
        set("unit","只");
        set( "type", "arms" );
        set( "material", "light_metal");
        set( "armor_class", 2 );
        set( "weight", 70 );
        set( "value", ({ 20, "gold" }) );
}






