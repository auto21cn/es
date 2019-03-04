#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic amulet", "恶魔护身符");
        add( "id", ({ "amulet" }) );
        set_short( "恶魔护身符" );
        set_long(
                "这是古恶魔战士专用的护身符\n"
        );
        set( "unit", "个");
        set( "type", "misc" );
        set( "material", "heavy_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":5, "divine":-7 ]) );
        set( "weight", 30 );
        set( "value", ({ 470, "silver" }) );
}
