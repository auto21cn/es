#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("general boots", "麻鞋");
        add( "id", ({ "boots" }) );
        set_short("general boots", "麻鞋");
        set_long(
                "a pair of normal boots .\n",
                "这是一双非常平凡的麻鞋，刘备以前就卖这个东西长大．\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "none":1, "acid":1 ]) );
        set( "weight", 70 );
        set( "value", ({ 127, "silver" }) );
}
