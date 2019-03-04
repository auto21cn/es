#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Bronze amulet", "青铜护身符");
        add( "id", ({ "amulet" }) );
        set_short( "青铜护身符");
        set_long(
                " 一个青铜护身符,重量很轻但是似乎能提供很好的保护力\n"
        );
        set("unit","个");
        set( "type", "misc" );
        set("material","light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 5 );
        set("no_sale",1) ;
        set( "value", ({ 60, "gold" }) );
}



