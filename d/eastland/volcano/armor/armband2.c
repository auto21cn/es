#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith armband", "矮灵臂环");
        add( "id", ({ "armband" }) );
        set_short("矮灵臂环");
        set_long(
                "这个臂环乃是经过祭师科拉克以冰雪力量炼制而成。\n"
        );
        set("unit","个");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






