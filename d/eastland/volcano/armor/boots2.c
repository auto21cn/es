#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith boots", "矮灵鞋");
        add( "id", ({ "boots" }) );
        set_short("矮灵鞋");
        set_long(
                "这双鞋乃是经过祭师科拉克以烈火力量炼制而成。\n"
        );
        set("unit","双");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 280, "gold" }) );
}






