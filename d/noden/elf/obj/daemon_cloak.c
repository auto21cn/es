#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic cloak", "恶魔披风");
        add( "id", ({ "cloak" }) );
        set_short( "恶魔披风" );
        set_long(
                "这是古恶魔战士所专用的披风 \n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "special_defense",
              ([ "evil":3, "divine":-4, "fire":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 530, "silver" }) );
}
