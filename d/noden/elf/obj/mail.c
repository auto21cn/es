#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail", "铠甲");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "铠甲" );
        set_long(
                "用特殊的金属所制成的铠甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 13 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "mental":3, "evil":-2 ]) );
                       
        set( "weight", 150 );
        set( "value", ({ 300, "silver" }) );
}






