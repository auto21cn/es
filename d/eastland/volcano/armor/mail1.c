#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith mail", "矮灵护甲");
        add( "id", ({ "mail" }) );
        set_short( "矮灵护甲");
        set_long(
                "这件护甲乃是经过祭师科拉克以精神力量炼制而成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "element");
        set( "armor_class", 27 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":5 ]) );
        set( "weight", 250 );
        set( "no_sell",1);
        set( "value", ({ 400, "gold" }) );
}






