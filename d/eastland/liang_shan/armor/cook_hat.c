#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("cook hat", "厨师帽");
        add( "id", ({ "hat" }) );
        set_short( "cook hat", "厨师帽");
        set_long(
                "A hat .\n",
                "这是一顶厨师专用的帽子，其上沾满油垢\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":4,"mental":1 ]) );
        set( "weight", 60 );
        set( "value", ({ 12, "gold" }) );
}



