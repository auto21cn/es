#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("thunder cape", "五雷天心护袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("thunder cape","五雷天心护袍");
        set_long(
                "This is a cape that can avoid thunder...\n",
                "这是一件红色的道袍，上面写著一些护身的符□，据说公孙胜\n"
                "呼风唤雨时必定会穿上这件罗真人送的法袍，以避免闪电误伤自己．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "mage" );
        set( "armor_class", 7 );
        set( "defense_bonus", 10 );
        set( "special_defense",(["electric":20 ]) );
        set( "weight", 70 );
        set( "value", ({ 1275, "silver" }) );
}