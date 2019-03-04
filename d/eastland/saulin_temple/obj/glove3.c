#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("black bracers", "黑□手钏");
        add( "id", ({"bracers","bracer" }) );
        set_short("黑□手钏");
        set_long(
"一双由黑□岩的石头制作成的手环, 可以帮助你在战斗中夺得胜利。\n"
        );
        set( "unit", "双");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 60 );
        set( "value", ({ 1500, "silver" }) );
}
