
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("shell armband", "龟甲臂环");
        add( "id", ({"armband" }) );
        set_short("龟甲臂环");
        set_long(
                "这是一个用乌龟甲壳做成的臂环，花花绿绿的满好看的。\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "material", "stone" );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 670, "silver" }) );
}
