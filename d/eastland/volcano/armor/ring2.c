#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("ring", "珊瑚戒指");
        add( "id", ({ "ring" }) );
        set_short("珊瑚戒指");
        set_long(
                "这是一只珊瑚戒指。\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 50 );
        set( "value", ({ 120, "gold" }) );
}






