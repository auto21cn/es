#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("holy amulet", "神圣护身符");
        add( "id", ({ "amulet" }) );
        set_short( "神圣护身符");
        set_long(
                "这个护身符能抗拒所有的邪恶。\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "evil":10 ]) );
        set( "weight", 50 );
        set( "value", ({ 300, "gold" }) );
}






