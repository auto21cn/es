#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("gold dauist hat", "紫金道冠");
        add( "id", ({ "hat" }) );
        set_short("紫金道冠");
        set_long(
                "这是传说中神仙所使用的道冠，能得到它的人往往很有仙缘． \n"
        );
        set("unit","顶");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "evil":7, "divine":-5, "mental":8 ]) );
        set( "weight", 60 );
        set( "value", ({ 450, "gold" }) );
}



