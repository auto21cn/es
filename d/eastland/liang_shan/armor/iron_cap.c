#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron cap", "冲天角铁头镤");
        add( "id", ({ "cap" }) );
        set_short( "iron cap", "冲天角铁头镤");
        set_long(
                "A iron cap .\n",
                "一顶很奇怪的金属高帽子，戴起来有一点怪异．\n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "adventurer");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 300, "gold" }) );
        set("extra_skills",(["whip":10]));
}



