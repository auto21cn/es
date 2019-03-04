#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silver armband", "银臂环");
        add( "id", ({"armband" }) );
        set_short("a silver armband", "银臂环");
        set_long(
                "An armband used by last dwarven guard.\n",
                "一个银臂环,有相当好的防护力\n"
        );
        set( "unit", "个");
        set( "type", "arms" );
        set( "material", "heavy_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 40);
        set( "value", ({ 770, "silver" }) );
}
