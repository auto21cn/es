#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("hoshi jade", "和氏璧");
        add( "id", ({ "jade" }) );
        set_short("和氏璧");
        set_long(
                "这是闻名於世的和氏璧，由上看色如羊脂，侧面则如碧玉，下方刻\n"
                "著: 受命於天，既寿且昌．相传是楚人卞和所发现，故名和氏．\n"
        );
        set( "no_sale",1);
        set( "unit", "块");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0);
        set( "defense_bonus", 8 );
        set( "special_defense",
             ([ "evil":8, "none":-7,"poison":5 ]) );
        set( "weight", 30 );
        set( "value", ({ 1880, "silver" }) );
}
