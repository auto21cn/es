#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron hat", "浑铁打就四方铁帽");
        add( "id", ({ "hat" }) );
        set_short( "iron hat", "浑铁打就四方铁帽");
        set_long(
                "A iron helmet .\n",
                "这是用镔铁铸成的方帽，如果再黑一点就很像毕业典礼用的那种． \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":5 ]) );
        set( "weight", 65 );
        set( "value", ({ 100, "gold" }) );
}



