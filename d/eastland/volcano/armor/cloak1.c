#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith cloak", "矮灵披风");
        add( "id", ({ "cloak" }) );
        set_short( "矮灵披风");
        set_long(
                "这件披风乃是经过祭师科拉克以神圣力量炼制而成。\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "divine":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 250, "gold" }) );
}






