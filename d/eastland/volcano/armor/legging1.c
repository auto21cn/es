#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith leggings", "矮灵胫甲");
        add( "id", ({ "leggings" }) );
        set_short("矮灵胫甲");
        set_long(
                "这件胫甲乃是经过祭师科拉克以邪恶力量炼制而成。\n"
        );
        set("unit","件");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 80 );
        set( "value", ({ 200, "gold" }) );
}






