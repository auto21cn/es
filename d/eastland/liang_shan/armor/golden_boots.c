#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden silk boots", "金线抹绿皂朝靴");
        add( "id", ({ "boots" }) );
        set_short("golden silk boots", "金线抹绿皂朝靴");
        set_long(
                "This is a pair of boots made of golden silk .\n",
                "这是用金线和丝绸作成的鞋子，美丽到你不忍心穿著它走路．\n"
        );
        set( "unit", "双");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 660, "silver" }) );
}
