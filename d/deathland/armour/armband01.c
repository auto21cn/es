#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("dwarven armband", "矮人臂环");
        add( "id", ({"armband" }) );
        set_short("a dwarven armband", "矮人臂环");
        set_long(
                "An armband used by dwarf.\n",
                "一个矮人专用的臂环\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "material", "light_metal" );
        set( "armor_class", 2 );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 720, "silver" }) );
}
