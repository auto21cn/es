#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("fire amulet", "火护身符");
        add( "id", ({ "amulet" }) );
        set_short("火护身符");
        set_long(
                "这个护身符听说曾被火神戴过。\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0 );
        set( "defense_bonus", 8 );
        set( "special_defense",
               ([ "fire":13 ]) );
        set( "no_sale",1);
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
}






