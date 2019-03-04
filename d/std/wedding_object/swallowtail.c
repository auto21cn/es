#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("swallowtail","燕尾礼服");
        add("id",({"suit"}) );
         set_short( "swallowtail","新郎燕尾服");
        set_long(
"This is a suit of wedding suit made of true white silk meterial.\n",
"这是一件白色的燕尾服，纯白的颜色代表纯洁无暇的爱情。\n"
        );
        set( "unit", "件" );
        set( "weight", 150 );
        set( "type", "body" );
        set("material","cloth" ) ;
        set( "armor_class", 28 );
        set( "defense_bonus", 5 );
        set( "no_sale", 1 );
        set( "value", ({ 318, "gold" }) );
}
