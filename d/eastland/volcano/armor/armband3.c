#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("water armband", "水臂环");
        add( "id", ({ "armband" }) );
        set_short( "水臂环");
        set_long(
                "这个臂环乃是龙王用魔力将水之精炼制而成。\n"
        );
        set("unit","个");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":-5, "fire":10 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






