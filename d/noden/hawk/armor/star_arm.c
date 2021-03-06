#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Star Armband","流星臂环" );
        add( "id", ({ "armband" }) );
        set_short( "流星臂环" );
        set_long(
                "一对由青玉制成的臂环，上面刻著淡淡的流星雨。\n"
        );
        set( "unit", "对" );
	set("material","element");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
	set( "extra_skills", (["tactic" : 5, "riding" : 5]) );
        set( "weight", 30 );
        set( "value", ({ 1300, "silver" }) );
}
